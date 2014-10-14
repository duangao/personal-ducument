#include "ui/ui.h"

#include "nemu.h"
#include "ui/breakpoint.h"
#include "ui/watchpoint.h"
#include <signal.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int nemu_state = END;
void init_bp_pool();
int getExpr(char *,bool *);
void insert_head(BP*);
void insert_head_wp(WP*);
void restart();
void cpu_exec(uint32_t);
int exec(swaddr_t);
BP* new_bp();
WP* new_wp();
BP* getHead();
WP* getHead_wp();
void free_bp(BP*);
void delete_N(int);
void delete_N_wp(int);
void deleteAll();
void deleteAll_wp();
void load_prog();
void init_dram();
/* We use the readline library to provide more flexibility to read from stdin. */
char* rl_gets() {
	static char *line_read = NULL;
	if (line_read) {
		free(line_read);
		line_read = NULL;
	}

	line_read = readline("(nemu) ");

	if (line_read && *line_read) {
		add_history(line_read);
	}

	return line_read;
}

/* This function will be called when you press <C-c>. And it will return to 
 * where you press <C-c>. If you are interesting in how it works, please
 * search for "Unix signal" in the Internet.
 */
static void control_C(int signum) {
	if(nemu_state == RUNNING) {
		nemu_state = INT;
	}
}

void init_signal() {
	/* Register a signal handler. */
	struct sigaction s;
	memset(&s, 0, sizeof(s));
	s.sa_handler = control_C;
	int ret = sigaction(SIGINT, &s, NULL);
	assert(ret == 0);
}

static void cmd_c() {
	if(nemu_state == END) {
		puts("The Program does not start. Use 'r' command to start the program.");
		return;
	}

	nemu_state = RUNNING;
	cpu_exec(-1);
	if(nemu_state != END) { nemu_state = STOP; }
}

static void cmd_r() {
	if(nemu_state != END) { 
		char c;
		while(1) {
			printf("The program is already running. Restart the program? (y or n)");
			fflush(stdout);
			scanf(" %c", &c);
			switch(c) {
				case 'y': goto restart_;
				case 'n': return;
				default: puts("Please answer y or n.");
			}
		}
	}

restart_:
	restart();
	nemu_state = STOP;
	cmd_c();
}

void main_loop() {
	char *cmd;
	while(1) {
		cmd = rl_gets();
		char *p = strtok(cmd, " ");
		if(p == NULL) {continue; }

		if(strcmp(p, "c") == 0) {cmd_c(); }
		else if(strcmp(p, "r") == 0) { cmd_r(); }
		else if(strcmp(p, "q") == 0) { return; }

		/* TODO: Add more commands */

		else if(strncmp(p,"si",2)==0){  //if command prefix is si

			if(nemu_state == END)
			{
				restart();
				nemu_state=STOP;
			}
			p=strtok(NULL," ");         

			if(p==NULL)			
			{	
				cpu_exec(1);
				nemu_state=STOP;
			}
			
			else if(isdigit(*p))
			{
				int number=*p-'0';
				while(isdigit(*++p))
				{	
					number=number*10+*p-'0';
				}
				cpu_exec(number); 
				nemu_state=STOP;

			}
			else {printf("Wrong parameter of si command!\n");}
		}
		else if(strncmp(p,"info",4)==0)
		{
			p=strtok(NULL," ");
			if(*p == 'r')
			{
				int i;
				for(i=R_EAX;i<=R_EDI;++i)	
				{	printf("%s(0x%x)   0x%x\n",regsl[i],(unsigned)&cpu.gpr[i]._32,reg_l(i));
				}
			}
			else if(*p == 'b')
			{
				BP *i=getHead();
				if(i == NULL)
				{
					printf("there is not breakpoint!\n");
					continue;
				}
				printf("NUM		Type	ADDRESS\n");
				for(;i!=NULL;i=i->next)
				{
					printf("%d		breakpoint	0x%x\n",i->NO,i->bp_location);
				}
			}
			else if(*p == 'w')
			{
				WP *i=getHead_wp();
				if(i == NULL)
				{
					printf("there is not watchpoint!\n");
					continue;
				}
				printf("NUM		Type		EXPRESSION\n");
				for(;i!=NULL;i=i->next)
				{
					printf("%d		watchpoint	%s\n",i->NO,i->expr);
				}
			}
		}
		else if(strcmp(p,"x")==0)
		{
			p=strtok(NULL," ");
			if(isdigit(*p))
			{
				int number=*p-'0';
				while(isdigit(*++p))
				{	
					number=number*10+*p-'0';
				}
				p=strtok(NULL," ");
				{
				bool *s=false;
					swaddr_t addr=getExpr(p,s);

					int i;
					for(i=1;i<=number;++i)
					{
						printf("%8x:	",addr);
						int len=exec(addr);
						swaddr_t addr_n;
						if(len >=4)
							addr_n=addr+3;
						else
							addr_n=addr+len-1;
						while(addr_n >= addr){
							printf("%02x ",swaddr_read(addr_n--,1));
						}
						addr+=len;

						printf("\n");
					}
				}
			}
			
			else {printf("Wrong address!\n");}
		}
		else if(strcmp(p,"p")==0)
		{
			p=strtok(NULL," ");
			bool *s=false;
			uint32_t result=getExpr(p,s);
			printf("result: %d\n",result);
		}
		else if(strcmp(p,"b")==0)
				{
					if(nemu_state == END)
					{
						printf("The program is not running now!Please input si [N] to execute!\n");
						continue;
					}
					else{
					p=strtok(NULL," ");
					if(*p!='*')
					{
						printf("wrong format of breakpoint!\n");
						return;
					}
					else
					{p++;}
					bool *s=false;
					swaddr_t addr=getExpr(p,s);
					BP *bp=new_bp();
					bp->origin_intr=swaddr_read(addr,1);
					bp->bp_location=addr;
					insert_head(bp);
					swaddr_write(addr,1,INT3_CODE);
					}
				}
		else if(strcmp(p,"d")==0)
		{
			    p=strtok(NULL," ");
				if(p==NULL)
				{
					deleteAll();
					deleteAll_wp();
				}
				else 
			{	
				int number=*p-'0';
				while(isdigit(*++p))
				{	
					number=number*10+*p-'0';
				}
				delete_N(number);
				delete_N_wp(number);
			}
		}	
		else if(strcmp(p,"w")==0)
		{
			p=strtok(NULL," ");
			WP *wp=new_wp();
			char *temp=p;
			int i=0;
			while(temp[i] != '\0')
			{
				wp->expr[i]=temp[i];
				++i;
			}
			bool *s=false;
			uint32_t expr=getExpr(p,s);
			wp->old_value=expr;
			insert_head_wp(wp);

		}

		else { printf("Unknown command '%s'\n", p); }
	}
}

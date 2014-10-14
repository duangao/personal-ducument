#include "ui/ui.h"
#include "nemu.h"
#include "ui/watchpoint.h"
#include <setjmp.h>

#define LOADER_START 0x100000
#define ESP_START   0x8000000
int exec(swaddr_t);
void load_prog();
void init_dram();
WP* getHead_wp();
uint32_t getExpr(char*,bool*);
char assembly[40];
jmp_buf jbuf;	/* Make it easy to perform exception handling */

extern uint8_t loader [];
extern uint32_t loader_len;

extern int quiet;

void restart() {
	/* Perform some initialization to restart a program */
	load_prog();
	memcpy(hwa_to_va(LOADER_START), loader, loader_len);
	cpu.esp=  ESP_START;
	cpu.eip = LOADER_START;

	init_dram();
}

static void print_bin_instr(swaddr_t eip, int len) {
	int i;
	printf("%8x:   ", eip);
	for(i = 0; i < len; i ++) {
		printf("%02x ", swaddr_read(eip + i, 1));
	}
	printf("%*.s", 50 - (12 + 3 * len), "");
}

void cpu_exec(volatile uint32_t n) {
	volatile uint32_t n_temp = n;

	setjmp(jbuf);
	WP *head;
	for(; n > 0; n --) {
		swaddr_t eip_temp = cpu.eip;
		int instr_len = exec(cpu.eip);
		
		head=getHead_wp();
	for(;head!=NULL;head=head->next)
		{
			bool *s=false;
			uint32_t value=getExpr(head->expr,s);
		   if(value != head->old_value)
		   {
			   printf("hit the watch point %d\n",head->NO);
			   printf("old value:%d\n",head->old_value);
			   printf("new value:%d\n",value);
				nemu_state=STOP;
				head->old_value=value;
		   }	   
		}

		cpu.eip += instr_len;

		if(n_temp != -1 || (enable_debug && !quiet)) {
			print_bin_instr(eip_temp, instr_len);
			puts(assembly);
		}

		if(nemu_state == INT) {
			printf("\n\nUser interrupt\n");
			return;
		} 
		else if(nemu_state == END) { return; }
	}
}

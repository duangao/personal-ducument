#include "ui/breakpoint.h"

#include "nemu.h"

#define NR_BP 32

static BP bp_pool[NR_BP];
static BP *head, *free_;

void init_bp_pool() {
	int i;
	for(i = 0; i < NR_BP - 1; i ++) {
		bp_pool[i].NO = i;
		bp_pool[i].next = &bp_pool[i + 1];
		bp_pool[i].state=0;
	}
	bp_pool[i].NO=i;
	bp_pool[i].next = NULL;

	head = NULL;
	free_ = bp_pool;
}

/* TODO: Implement the function of breakpoint */
BP* new_bp()
{
	BP* temp;
	if(free_== NULL)
		assert(0);
	else
		temp=free_;
	free_=free_->next;
	return temp;	
}
void free_bp(BP *bp)
{
	BP* temp=free_->next;
	bp->next=temp;
	free_->next=bp;
}
void insert_head(BP *bp)
{
	if(head == NULL)
	{
		head=bp;
		head->next=NULL;
	}
	else
	{
		BP *i=head;
		for(;i->next!=NULL;i=i->next)
		{}
		bp->next=i->next;
		i->next=bp;
	}
}
BP* getHead()
{
	return head;
}
void delete_N(int n)
{
	BP *h=head;
	if(h->NO == n)
	{
		head=head->next;
		free_bp(h);
	}
	else if(h->next->NO==n)
	{
		h=h->next;
		head->next=head->next->next;
		free_bp(h);
	}
	else
	{
		for(;h->next->NO != n;h=h->next)
			h=h->next;
		BP *k=h->next;
		h->next=k->next;
		free_bp(k);
	}
}
void deleteAll()
{
	BP *i=head;
	for(;i!=NULL;)
	{
		head=head->next;
		free_bp(i);
		i=head;
	}
}

#include "ui/watchpoint.h"

#include "nemu.h"

#define NR_WP 32

static WP wp_pool[NR_WP];
static WP *head, *free_;

void init_wp_pool() {
	int i;
	for(i = 0; i < NR_WP - 1; i ++) {
		wp_pool[i].NO = i;
		wp_pool[i].next = &wp_pool[i + 1];
	}
	wp_pool[i].next = NULL;

	head = NULL;
	free_ = wp_pool;
}
WP* getHead_wp()
{
	return head;
}
WP* new_wp()
{
	WP* temp;
	if(free_== NULL)
		assert(0);
	else
		temp=free_;
	free_=free_->next;
	return temp;	
}
void free_wp(WP *wp)
{
	WP* temp=free_->next;
	wp->next=temp;
	free_->next=wp;
}
void insert_head_wp(WP *wp)
{
	if(head == NULL)
	{
		head=wp;
		head->next=NULL;
	}
	else
	{
		WP *i=head;
		for(;i->next!=NULL;i=i->next)	
		{}
		wp->next=i->next;
		i->next=wp;
	}
}
void delete_N_wp(int n)
{
	WP *h=head;
	if(h== NULL)
		return;
	if(h->NO == n)
	{
		head=head->next;
		free_wp(h);
	}
	if(h->next==NULL)
		return;
	else if(h->next->NO==n)
	{
		h=h->next;
		head->next=head->next->next;
		free_wp(h);
	}
	else
	{
		for(; h->next->NO != n;h=h->next)
		{
			if(h->next == NULL)
				return;
			h=h->next;
		}
		WP *k=h->next;
		h->next=k->next;
		free_wp(k);
	}
}
void deleteAll_wp()
{
	WP *i=head;
	for(;i!=NULL;)
	{
		head=head->next;
		free_wp(i);
		i=head;
	}
}

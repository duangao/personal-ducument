#ifndef __UI_WATCHPOINT_H__
#define __UI_WATCHPOINT_H__

#include "common.h"

#define SIZE 30
typedef struct watchpoint {
	int NO;
	struct watchpoint *next;

	char expr[SIZE];
	uint32_t old_value;
}WP;
#endif

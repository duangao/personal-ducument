#include "exec/helper.h"

#include "ui/ui.h"

#include "nemu.h"
#include "ui/breakpoint.h"
BP* new_bp();
BP* getHead();
uint32_t exec(uint32_t);
make_helper(inv) {
	/* invalid opcode */

	uint8_t temp[8];
	((uint32_t *)temp)[0] = instr_fetch(eip, 4);
	((uint32_t *)temp)[1] = instr_fetch(eip + 4, 4);
	printf("invalid opcode(eip = 0x%08x): %02x %02x %02x %02x %02x %02x %02x %02x ...\n", 
			eip, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7]);

	assert(0);
}

enum{STATE_B,STATE_C,STATE_R};
make_helper(int3) {
	/* A breakpoint is hit! Do something here! */
BP *bp=getHead();
while(bp!=NULL && bp->bp_location != cpu.eip)
	bp=bp->next;
switch(bp->state)
{
	case STATE_B:
		{
			cpu.eip-=1;
			printf("Make one breakpoint at%x !\n",bp->bp_location);
			bp->state=STATE_C;
			break;
		}
	case STATE_C:
		{
			swaddr_write(bp->bp_location,1,bp->origin_intr);
			//printf("intr:%x\n",bp->origin_intr);
			printf("Show the origin instruction !\n");
			bp->state=STATE_R;
			cpu.eip+=exec(bp->bp_location)-1;
			break;
		}
	case STATE_R:
		{
			swaddr_write(bp->bp_location,1,INT3_CODE);
			break;
		}
}
		return 1;
}

make_helper(nemu_trap) {
	printf("nemu: HIT \33[1;31m%s\33[0m TRAP at eip = 0x%08x\n\n", (cpu.eax == 0 ? "GOOD" : "BAD"), cpu.eip);
	nemu_state = END;

	print_asm("nemu trap");
	return 1;
}

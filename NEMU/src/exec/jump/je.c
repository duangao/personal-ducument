#include "cpu/reg.h"
#include "exec/helper.h"

make_helper(je)
{
	swaddr_t addr=instr_fetch(cpu.eip+1,1);
	cpu.eip+=addr;
	print_asm("je %x",cpu.eip+2);
	return 2;
}

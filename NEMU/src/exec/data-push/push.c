#include "cpu/reg.h"
#include "exec/helper.h"

make_helper(push)
{
	int reg_code=instr_fetch(cpu.eip,1)&0x7;
	cpu.esp-=4;
	reg_l(R_ESP)=reg_l(reg_code);
	print_asm("push %%%s",regsl[reg_code]);
	return 1;
}

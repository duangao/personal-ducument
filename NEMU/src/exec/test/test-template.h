#include "exec/helper.h"
#include "exec/template-start.h"
#include "cpu/modrm.h"
#include "even_one.h"
make_helper(concat(test_rm2r_,SUFFIX))
{
	ModR_M m;
	m.val=instr_fetch(eip+1,1);
	if(m.mod == 3)
	{
		int result=REG(m.R_M)&REG(m.reg);

		if(result == 0)
			cpu.eflags.zf=1;
		if((result<REG(m.R_M)) || (result<REG(m.reg)))
			cpu.eflags.cf=1;
		if(result<0)
			cpu.eflags.sf=1;
		if( ( (REG(m.R_M)<0 )== (REG(m.reg)<0) )  && ( (result<0) != (REG(m.R_M)<0)) &&( (result<0) != (REG(m.reg)<0))   )
			cpu.eflags.of=1;
		if(even_one(result&0xFF))
			cpu.eflags.pf=1;

		print_asm("test" str(SUFFIX) " %%%s,%%%s",REG_NAME(m.R_M),REG_NAME(m.reg));
		return 2;
	}
	else
	{
		swaddr_t addr;
		int result=REG(m.R_M)&REG(m.reg);
		int len=read_ModR_M(eip+1,&addr);
		if(result == 0)
			cpu.eflags.zf=1;
		if((result<MEM_R(addr)) || (result<REG(m.reg)))
			cpu.eflags.cf=1;
		if(result<0)
			cpu.eflags.sf=1;
		if( ( (MEM_R(addr)<0 )== (REG(m.reg)<0) )  && ( (result<0) != (MEM_R(addr)<0)) &&( (result<0) != (REG(m.reg)<0))   )
			cpu.eflags.of=1;
		if(even_one(result&0xFF))
			cpu.eflags.pf=1;

		print_asm("test" str(SUFFIX) " %s,%%%s",ModR_M_asm,REG_NAME(m.reg));
		return len+1;
	}
}
#include "exec/template-end.h"

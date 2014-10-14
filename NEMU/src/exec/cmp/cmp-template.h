#include "exec/helper.h"
#include "exec/template-start.h"
#include "cpu/modrm.h"
//#include "../test/even_one.h"
extern bool even_one(int);
make_helper(concat(cmp_i2rm_,SUFFIX))
{
	ModR_M m;
	DATA_TYPE imm;
	m.val=instr_fetch(eip+1,1);
	if(!((m.val&0x38 )== 0x38))
	{
		print_asm("%s\n","wrong!");
		assert(0);
	}
	
	if(m.mod==3)
	{
		imm=instr_fetch(eip+1+1,DATA_BYTE);
		int result=REG(m.R_M)-imm;
		if(result == 0)
			cpu.eflags.zf=1;
		if((result<REG(m.R_M)) || (result<imm))
			cpu.eflags.cf=1;
		if(result<0)
			cpu.eflags.sf=1;
		if( ( (REG(m.R_M)<0) == (imm<0) ) && ((result<0) != (REG(m.R_M)<0))&& ((result<0)!=(imm<0)))
			cpu.eflags.cf=1;
		if(even_one(result&0xFF))
			cpu.eflags.pf=1;		

		print_asm("cmp" str(SUFFIX) "$0x%x,%%%s",imm,REG_NAME(m.R_M));
		
		return 1+DATA_BYTE+1;
	}
	else
	{
		swaddr_t addr;
		int len=read_ModR_M(eip+1,&addr);
		imm=instr_fetch(eip+1+len,DATA_BYTE);
     	int result=REG(m.R_M)-imm;
		if(result == 0)
			cpu.eflags.zf=1;
		if((result<REG(m.R_M)) || (result<imm))
			cpu.eflags.cf=1;
		if(result<0)
			cpu.eflags.sf=1;
		if( ( (REG(m.R_M)<0)==(imm<0)) && ((result<0) != (REG(m.R_M)<0))&& ((result<0)!=(imm<0)))
			cpu.eflags.cf=1;
		if(even_one(result&0xFF))
			cpu.eflags.pf=1;		

		print_asm("cmp" str(SUFFIX) " $0x%x,%s",imm,ModR_M_asm);
		return len+DATA_BYTE+1;
	}
}

make_helper(concat(cmp_r2rm_,SUFFIX))
{
	ModR_M m;
	m.val=instr_fetch(eip+1,1);
	if(m.mod==3)
	{
//		print_asm("cmp" str(SUFFIX) " %%%s,%%%s",REG_NAME(m.reg),REG_NMAE(m.R_M));
		return 2;
	}
	else
	{
		swaddr_t addr;
		int len=read_ModR_M(eip+1,&addr);
		

//		print_asm("mov" str(SUFFIX) " %%%s,%s",REG_NAME(m.reg),ModR_M_asm);
		return len+1;
	}
}
make_helper(concat(cmp_rm2r_,SUFFIX))
{
	ModR_M m;
	m.val=instr_fetch(eip+1,1);
	if(m.mod==3)
	{
//		print_asm("cmp" str(SUFFIX) " %%%s,%%%s",REG_NAME(m.R_M),REG_NMAE(m.reg));
		return 2;
	}
	else
	{
		swaddr_t addr;
		int len=read_ModR_M(eip+1,&addr);
		

//		print_asm("mov" str(SUFFIX) " %%%s,%s",ModR_M_asm,REG_NAME(m.reg));
		return len+1;
	}
}
make_helper(concat(cmp_i2rm_et_,SUFFIX))
{
	ModR_M m;
	DATA_TYPE imm;
	m.val=instr_fetch(eip+1,1);
	if(((m.val&0x38 )== 0x38))
	{
	
	
	if(m.mod==3)
	{
		imm=instr_fetch(eip+1+1,1);
		imm=(int)imm;
		int result=REG(m.R_M)-imm;
		if(result == 0)
			cpu.eflags.zf=1;
		if((result<REG(m.R_M)) || (result<imm))
			cpu.eflags.cf=1;
		if(result<0)
			cpu.eflags.sf=1;
		if( ( (REG(m.R_M)<0) == (imm<0) ) && ((result<0) != (REG(m.R_M)<0))&& ((result<0)!=(imm<0)))
			cpu.eflags.cf=1;
		if(even_one(result&0xFF))
			cpu.eflags.pf=1;		

		print_asm("cmp" str(SUFFIX) " $0x%x,%%%s",imm,REG_NAME(m.R_M));
		return 3; 
	}
	else
	{
		swaddr_t addr;
		int len=read_ModR_M(eip+1,&addr);
		imm=instr_fetch(eip+1+len,1);
     	int result=REG(m.R_M)-imm;
		if(result == 0)
			cpu.eflags.zf=1;
		if((result<REG(m.R_M)) || (result<imm))
			cpu.eflags.cf=1;
		if(result<0)
			cpu.eflags.sf=1;
		if( ( (REG(m.R_M)<0)==(imm<0)) && ((result<0) != (REG(m.R_M)<0))&& ((result<0)!=(imm<0)))
			cpu.eflags.cf=1;
		if(even_one(result&0xFF))
			cpu.eflags.pf=1;		

		print_asm("cmp" str(SUFFIX) " $0x%x,%s",imm,ModR_M_asm);
		return len+2;
	}

}
	else if((m.val&0x28)==0x28)
	{
		if(m.mod==3)
		{
		imm=instr_fetch(eip+1+1,1);
		imm=(int)imm;
		int result=REG(m.R_M)-imm;
		if(result == 0)
			cpu.eflags.zf=1;
		if((result<REG(m.R_M)) || (result<imm))
			cpu.eflags.cf=1;
		if(result<0)
			cpu.eflags.sf=1;
		if( ( (REG(m.R_M)<0) == (imm<0) ) && ((result<0) != (REG(m.R_M)<0))&& ((result<0)!=(imm<0)))
			cpu.eflags.cf=1;
		if(even_one(result&0xFF))
			cpu.eflags.pf=1;		
		print_asm("sub" str(SUFFIX) " $0x%x,%%%s",imm,REG_NAME(m.R_M));
		REG(m.R_M)=result;
		return 3; 
	}
	else
	{
		swaddr_t addr;
		int len=read_ModR_M(eip+1,&addr);
		imm=instr_fetch(eip+1+len,DATA_BYTE);
     	int result=REG(m.R_M)-imm;
		if(result == 0)
			cpu.eflags.zf=1;
		if((result<REG(m.R_M)) || (result<imm))
			cpu.eflags.cf=1;
		if(result<0)
			cpu.eflags.sf=1;
		if( ( (REG(m.R_M)<0)==(imm<0)) && ((result<0) != (REG(m.R_M)<0))&& ((result<0)!=(imm<0)))
			cpu.eflags.cf=1;
		if(even_one(result&0xFF))
			cpu.eflags.pf=1;		

		print_asm("sub" str(SUFFIX) " $0x%x,%s",imm,ModR_M_asm);
		REG(m.R_M)=result;
		return len+2;
	}
	}
return 0;
}
#include "exec/template-end.h"

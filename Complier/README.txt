in.cpp 文件是求解中缀表达式的源文件
pre.cpp 文件是求解前缀表达式的源文件

下面是个人的语法定义：
前缀表达式：
	    expr="(" op number number ")" | "（" expr "）" |number
        number= [0-9]*
        op='+' | '-' | '* | '/'
中缀表达式：
		expr=term | (('+'|'-')term)*
		term=factor | (('*'|'/')factor)* 
		factor=number|"(" expr ")"
		number=[0-9]*

扩展后的中缀表达式：
digti=[0-9]+ 
fact1=digit | "(" exp3 ")" 
fact2=(！|~)fact1    
term = fact2 ( ( "*" | "/" ) fact2) *  
exp = term ( ( "+" | "-" ) term) * 
exp2=exp ((<=|>=|<|>|==|!=) exp)* 
exp3=exp2 ((&&| || ) exp2)*

生成的exe文件均可以连续的进行输入表达式求值，输入q退出程序

#include "common.h"
#include"cpu/reg.h"
uint32_t swaddr_read(swaddr_t addr, size_t len);
struct expr
{
	char* error;
	int result;
	char *error_position;

}expr;
void init_regex(){}
extern struct expr getFactor(char**);
extern struct expr getExpression(char**);
extern struct expr getExpr3(char**);
bool Is(char **stream, const char* test)
{
	size_t length = strlen(test);
	char *lookup = *stream;
	while (*lookup == ' '){
		lookup++;
	}

	if (strncmp(lookup, test, length) == 0)
	{

		*stream = lookup + length;
		return true;
	}
	else
		return false;
}

struct expr getFactor2(char **stream)
{
	struct expr fact2 = { 0, 0, 0 };
	
	char *lookup = *stream;
	while (*lookup == ' ')
		lookup++;
	char op = *lookup;

	if (op == '*' || op == '~' || op=='!')
	{
		lookup++;
		struct expr fact1= { 0, 0, 0 };
		fact1 = getFactor(&lookup);

		if (fact1.error == 0)
		{
			switch (op)
			{
			case '*':{fact2.result=*((int*)fact1.result);break;}
			case '~':{fact2.result = ~fact1.result;  break; }
			case'!':{fact2.result=!fact1.result;break;}
			default:
			{fact2.error = "wrong charactor before digit or epxr!\n";
			fact2.error_position = lookup; }
			}
		}
		else { fact2.error = "wrong factor after * or ~!\n"; fact2.error_position = lookup; }
	}
	else fact2 = getFactor(&lookup);
	if (fact2.error == 0)
		*stream = lookup;
	return fact2;
}

struct expr GetNumber(char** stream)
{
	struct expr number = { 0, 0, 0 };											

	char* lookup = *stream;
	while ((*lookup) == ' ') lookup++;
	if(*lookup=='$')
	{
		lookup++;
		if(Is(&lookup,"eax"))
		{
			number.result=(unsigned)cpu.eax;
			*stream=lookup;
			return number;
		}
		else if(Is(&lookup,"ebx")){
			number.result=(unsigned)cpu.ebx;
			*stream=lookup;
			return number;
		}
		else if(Is(&lookup,"ecx")){
			number.result=(unsigned)cpu.ecx;
			*stream=lookup;
			return number;
		}
		else if(Is(&lookup,"edx")){
			number.result=(unsigned)cpu.edx;
			*stream=lookup;
			return number;
		}
		else if(Is(&lookup,"esp")){
			number.result=(unsigned)cpu.esp;
			*stream=lookup;
			return number;
		}
		else if(Is(&lookup,"ebp")){
			number.result=(unsigned)cpu.ebp;
			*stream=lookup;
			return number;
		}
		else if(Is(&lookup,"esi")){
			number.result=(unsigned)cpu.esi;
			*stream=lookup;
			return number;
		}
		else if(Is(&lookup,"edi")){
			number.result=(unsigned)cpu.edi;
			*stream=lookup;
			return number;
		}
		else
		{
			number.error="the wrong name of registers!";
			number.error_position=lookup;
			return number;
		}
	}
	bool flag = false;
	bool symbol = false;
	int base = 10;
	if (*lookup == '0'&& *(lookup + 1) == 'x')
	{
		lookup += 2;
		char *temp = lookup;
		base = 16;
		while (((*temp <= '9' )&& (*temp >= '0' ) ) ||  ( (*temp >= 'a')&&( *temp <= 'z')))
		{
			switch (*temp)
			{
			case 'a':*temp = '9'+1; break;
			case 'b':*temp = '9'+2; break;
			case 'c':*temp = '9'+3; break;
			case 'd':*temp = '9'+4; break;
			case 'e':*temp = '9'+5; break;
			case 'f':*temp = '9'+6; break;
			default:break;
			}
			temp++;
		}

	}
	if (*lookup == '-')
	{
		symbol = true;
		lookup++;
	}
	while (true)
	{
		if ((*lookup) <= ('9'+6) && (*lookup) >= '0')
		{
			number.result = number.result * base + (*lookup) - '0';
			++lookup;
			flag = true;
		}
		else
			break;
	}
	if (flag)										
		*stream = lookup;
	else										
	{
		number.error = "there need a number!\n";
		number.error_position = lookup;
	}
	if (symbol)
		number.result = -number.result;

	return number;

}

struct expr getFactor(char** stream)
{
	struct expr result= { 0, 0, 0 };
	char *lookup = *stream;
	result = GetNumber(&lookup);

	if (result.error == 0)
	{
		*stream = lookup;
		return result;
	}

	else
	{
		if (Is(&lookup, "("))
		{
			result = getExpr3(&lookup);
			if (Is(&lookup, ")"))
			{
				*stream = lookup;
				return result;
			}
			else
			{
				result.error = "there need right brackt";
				result.error_position = lookup;
			}
		}
		else
		{
			result.error = "there need left brackt";
			result.error_position = lookup;
		}
	}

	return result;
}

struct expr getTerm(char** stream)
{
	struct expr result = { 0, 0, 0 };
	char *lookup = *stream;
	result = getFactor2(&lookup);
	if (result.error == 0)
	{
		while (true)
		{
			char op = 0;
			if (Is(&lookup, "*"))
				op = '*';
			else if (Is(&lookup, "/"))
				op = '/';
			else if (Is(&lookup, "%"))
				op = '%';
			else
				break;
			if (op)
			{
				struct expr right = getFactor2(&lookup);
				if (result.error == 0)
				{
					switch (op)
					{
					case '*':
						result.result *= right.result; break;
					case '/':
					{
						if (right.result == 0)
						{
							result.error = "the number divided can not be 0!\n";
							result.error_position = lookup;
							return result; break;
						}
						else
							result.result /= right.result; break;

					}
					case '%':
						result.result %= right.result; break;
					}
				}
				else
				{
					result.error = "there is wrong factor!\n";
					result.error_position = lookup; break;
				}
			}
		}
	}
	if (result.error == 0)
	{
		*stream = lookup;
	}

	return result;
}


struct expr getExpression(char** stream)
{

	struct expr result = { 0, 0, 0 };
	char *lookup = *stream;
	result = getTerm(&lookup);
	while (true)
	{
		char op = 0;
		if (Is(&lookup, "+"))
			op = '+';
		else if (Is(&lookup, "-"))
			op = '-';
		else
			break;
		if (op)
		{
		struct	expr right = getTerm(&lookup);
			if (right.error == 0)
			{
				switch (op)
				{
				case '+':
					result.result += right.result; break;
				case '-':
					result.result -= right.result; break;
				}
			}
			else
			{
				result.error = "the right number is wrong!\n";
				result.error_position = lookup; break;
			}
		}
	}
	if (result.error == 0)
	{
		*stream = lookup;
		return result;
	}
	return result;

}

struct expr getExpr2(char **stream)
{
	struct expr result = { 0, 0, 0 };
	char *lookup = *stream;
	result = getExpression(&lookup);

	while (true)
	{
		int op = 0;

		enum{ ME = 256, LE, EQ, NE, M, L };

		if (Is(&lookup, ">="))
			op = ME;
		else if (Is(&lookup, "<="))
			op = LE;
		else if (Is(&lookup, "=="))
			op = EQ;
		else if (Is(&lookup, "!="))
			op = NE;
		else if (Is(&lookup, ">"))
			op = M;
		else if (Is(&lookup, "<"))
			op = L;
		else
			break;

		if (op)
		{
		struct	expr right = { 0, 0, 0 };
			right = getExpression(&lookup);

			if (right.error == 0)
			{

				switch (op)
				{
				case ME:
					result.result = (result.result >= right.result); break;
				case LE:
					result.result = (result.result <= right.result); break;
				case EQ:
					result.result = (result.result == right.result); break;
				case NE:
					result.result = (result.result != right.result); break;
				case M:
					result.result = (result.result > right.result); break;
				case L:
					result.result = (result.result <right.result); break;
				default:{result.error = "wrong operator!\n"; result.error_position = lookup; }
				}
			}
			else
			{
				result.error = "the right expr is wrong!\n";
				result.error_position = lookup; break;
			}
		}
	}
	if (result.error == 0)
	{
		*stream = lookup;
		return result;
	}
	return result;
}
struct expr getExpr3(char**stream)
{

	struct expr result = { 0, 0, 0 };
	char *lookup = *stream;
	result = getExpr2(&lookup);
	while (true)
	{
		int op = 0;

		enum{ AND = 255, OR };

		if (Is(&lookup, "&&"))
			op = AND;
		else if (Is(&lookup, "||"))
			op = OR;

		else
			break;

		if (op)
		{
			struct expr right= { 0, 0, 0 };
			right= getExpr2(&lookup);

			if (right.error == 0)
			{

				switch (op)
				{
				case AND:
					result.result = (result.result && right.result); break;
				case OR:
					result.result = (result.result || right.result); break;

				default:{result.error = "wrong operator!\n"; result.error_position = lookup; }
				}
			}
			else
			{
				result.error = "the right expr is wrong!\n";
				result.error_position = lookup; break;
			}
		}
	}
	if (result.error == 0)
	{
		*stream = lookup;
		return result;
	}
	return result;

}
uint32_t getExpr(char *e, bool *success)
{
	return getExpr3(&e).result;
}


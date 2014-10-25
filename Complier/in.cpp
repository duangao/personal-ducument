#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class expr
{

public:
	char* error;
	int result;
	char *error_position;
	expr() :error(0), result(0), error_position(0){}

};
extern expr getFactor(char* &stream);
extern expr getExpression(char* &stream);
extern expr getExpr3(char *&stream);
bool Is(char *&stream,const char* test)
{
	size_t length = strlen(test);
	char *lookup = stream;
	while (*lookup == ' '){
		lookup++;
	}
	
	if (strncmp(lookup, test, length) == 0)
	{
		
		stream = lookup + length;
		return true;
	}
	else
		return false;
}

char IsOperator(char* &stream)
{

	if (Is(stream, "+") || Is(stream, "-") || Is(stream, "*") || Is(stream, "/") || Is(stream, "%") || Is(stream, ">=") || Is(stream, "<=") || Is(stream, "<") || Is(stream, ">") || Is(stream, "==") || Is(stream, "!="))
		return stream[-1];
	else
		return false;
}
expr getFactor2(char *&stream)
{
	expr fact2;
	char *lookup = stream;
	while (*lookup == ' ')
		lookup++;
	char op = *lookup;
	
	if (op=='*'|| op== '~')
	{
		lookup++;
		expr fact1 = getFactor(lookup);
		
		if (fact1.error == 0)
		{
			switch (op)
			{
			case '*':break;
			case '~':{fact2.result = ~fact1.result;  break; }
			default:
				{
					fact2.error = "wrong charactor before digit or epxr!\n";
					fact2.error_position = lookup; }
			}
		}
		else { fact2.error = "wrong factor after * or ~!\n"; fact2.error_position = lookup; }
	}
	else fact2 = getFactor(lookup);
	if (fact2.error == 0)
		stream = lookup;
	return fact2;
}

expr GetNumber(char* &stream)
{
	expr number;											//存储结果，为一个expr类对象
	char* lookup = stream;
	while ((*lookup) == ' ') lookup++;
	bool flag = false;
	bool symbol = false;
	int base = 10;
	if (*lookup == '0'&& *(lookup + 1) == 'x')
	{
		lookup += 2;
		char *temp = lookup;
		base = 16;
		while (*temp <= 9 && *temp >= 0 || *temp >= 'a'&& *temp <= 'z')
		{
			switch (*temp)
			{
			case 'a':*temp = 10; break;
			case 'b':*temp = 11; break;
			case 'c':*temp = 12; break;
			case 'd':*temp = 13; break;
			case 'e':*temp = 14; break; 
			case 'f':*temp = 15; break;

			}
		}
		
	}
	if (*lookup == '-')
	{
		symbol = true;
		lookup++;
	}
	while (true)
	{
		if ((*lookup) <= '9' && (*lookup) >= '0')
		{
			number.result = number.result * base+ (*lookup) - '0';
			++lookup;
			flag = true;
		}
		else
			break;
	}
	if (flag)										//获得当前开头的数字，并将当前指针所指调整到数字后面一位
		stream = lookup;
	else											//当前开头开始的不是数字，当前指针不变
	{
		number.error = "there need a number!\n";
		number.error_position = lookup;
	}
	if (symbol)
		number.result = -number.result;
	
	return number;

}

expr getFactor(char* &stream)
{
	expr result;
	char *lookup = stream;
	result = GetNumber(lookup);
	
	if (result.error == 0)
	{
		stream = lookup;
		return result;
	}

	else
	{
		if (Is(lookup, "("))
		{
			result= getExpr3(lookup);
			if (Is(lookup, ")"))
			{
				stream = lookup;
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

expr getTerm(char* &stream)
{
	expr result;
	char *lookup = stream;
	result = getFactor2(lookup);
	if (result.error == 0)
	{
		while (true)
		{
			char op = 0;
			if (Is(lookup, "*"))
				op = '*';
			else if (Is(lookup, "/"))
				op = '/';
			else if (Is(lookup, "%"))
				op = '%';
			else
				break;
			if (op)
			{
				expr right = getFactor2(lookup);
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
		stream = lookup;
	}
	
	return result;
}


expr getExpression(char* &stream)
{

		expr result;
		char *lookup = stream;
		result = getTerm(lookup);
		while (true)
		{
			char op = 0;
			if (Is(lookup, "+"))
				op = '+';
			else if (Is(lookup, "-"))
				op = '-';
			else
				break;
			if (op)
			{
				expr right = getTerm(lookup);
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
			stream = lookup;
			return result;
		}
		return result;
	
}

expr getExpr2(char *&stream)
{
	expr result;
	char *lookup = stream;
	result = getExpression(lookup);
	
	while (true)
	{
		int op=0;
		
		enum{ME=256,LE,EQ,NE,M,L};

		if (Is(lookup, ">="))
			op = ME;
		else if (Is(lookup, "<="))
			op = LE; 
		else if (Is(lookup, "=="))
			op = EQ;
		else if (Is(lookup, "!="))
			op = NE;
		else if (Is(lookup, ">"))
			op = M;
		else if (Is(lookup, "<"))
			op = L;
		else
			break;
		
		if (op)
		{
			expr right = getExpression(lookup);
			
			if (right.error == 0)
			{
				
				switch (op)
				{
				case ME:
					result.result =(result.result>=right.result); break;
				case LE:
					result.result = (result.result <= right.result); break;
				case EQ:
					result.result = (result.result == right.result); break;
				case NE:
					result.result = (result.result != right.result); break;
				case M:
					result.result = (result.result > right.result); break;
				case L:
					result.result =( result.result <right.result); break;
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
		stream = lookup;
		return result;
	}
	return result;
}
expr getExpr3(char* &stream)
{

	expr result;
	char *lookup = stream;
	result = getExpr2(lookup);

	while (true)
	{
		int op = 0;

		enum{ AND=255,OR };

		if (Is(lookup, "&&"))
			op = AND;
		else if (Is(lookup, "||"))
			op = OR;
		
		else
			break;

		if (op)
		{
			expr right = getExpr2(lookup);

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
		stream = lookup;
		return result;
	}
	return result;

}
int main()
{
	while (true)
	{
		char input[200];
		cout << "please input expression!\n" << ends;
		cin>>input;
			{
				if (input[0] == 'q')
					return 0;
	
				char* stream = input;
				expr result = getExpr3(stream);

				if (result.error == 0)
				{
					cout << "result is: " << result.result << endl;
				}
				else
				{
					cout << "wrong information: " << result.error << endl;
					cout << "wrong location: " << result.error_position << endl;
				}
			}
	}

	return 0;
}


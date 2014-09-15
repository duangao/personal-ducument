#include<iostream>
using namespace std;
class expr
{
	
public:
	char* error;
	int result;
	char *error_position;
	expr():error(0),result(0),error_position(0){}

};
bool Is(char *&stream,const char* test)	
{
	size_t length = strlen(test);
	char *lookup = stream;
	while (*lookup == ' '){
		lookup++; 
	}

	if (strncmp(lookup, test, length)==0)
	{
		stream = lookup + length;
		return true;
	}
	else
		return false;
}

char IsOperator(char* &stream)
{

	if (Is(stream, "+") || Is(stream, "-") || Is(stream, "*") || Is(stream, "/"))
		return stream[-1];
	else
		return false;
}
expr GetNumber(char* &stream)
{
	expr number;											//存储结果，为一个expr类对象
	char* lookup = stream;									
	while ((*lookup) == ' ') lookup++;
	bool flag = false;

	while (true)
	{
		if ((*lookup )<= '9' && (*lookup) >= '0')
		{
			number.result = number.result * 10 + (*lookup) - '0';
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
	return number;

}
expr Getexpression(char* &stream)
{
	expr expression;
	char *lookup = stream;
	expression = GetNumber(lookup);

	if (expression.error)
	{
		if (Is(lookup, "("))
		{	
			expression.error = 0;

			char op = 0;
			if (op=IsOperator(lookup))
			{
				expr left_expr = Getexpression(lookup);
				if (left_expr.error)
					return left_expr;

				char *copy_lookup = lookup;
				
				expr right_expr = Getexpression(lookup);
				if (right_expr.error )
					return right_expr;

				switch (op)
				{
					case '+':
						expression.result = left_expr.result + right_expr.result; break;
					case '-':
						expression.result = left_expr.result - right_expr.result; break;
					case '*':
						expression.result = left_expr.result * right_expr.result; break;
					case '/':
					{
						if (right_expr.result == 0)
						{
							expression.error = "the number divided can not be zero!\n";
							expression.error_position = copy_lookup; break;
						}
						else
						{
							expression.result = left_expr.result / right_expr.result; break;
						}
					}
					default:
					{
						expression.error = "the wrong operator!\n";
						expression.error_position = lookup;
						return expression;
					}

				}

			}
			else
			{
				expression= Getexpression(lookup);
				if (expression.error != 0) return expression;
			}

			if (!Is(lookup, ")"))
			{
				expression.error = "there need right bracket!\n";
				expression.error_position = lookup;
			}
		}
	}
	if(expression.error==0) 					//成功获得了数字，因此将stream指针置于数字后面
	{
		stream = lookup;
	}
	return expression;
}
int main()
{
	
	while (true)
	{
		char input[200];
		cout << "输入前缀表达式:\n" << ends;
		gets_s(input);
		{
			if (input[0] == 'q')
				return 0;

			char* stream = input;
			expr result = Getexpression(stream);

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

	system("pause");
	return 0;
}



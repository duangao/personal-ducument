#include<iostream>
using namespace std;
class expr
{

public:
	char* error;
	int result;
	char *error_position;
	expr() :error(0), result(0), error_position(0){}

};
bool Is(char *&stream, const char* test)
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
		if ((*lookup) <= '9' && (*lookup) >= '0')
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
expr getExpression(char* &stream);
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
			result= getExpression(lookup);
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
	result = getFactor(lookup);
	if (result.error == 0)
	{
		while (true)
		{
			char op = 0;
			if (Is(lookup, "*"))
				op = '*';
			else if (Is(lookup, "/"))
				op = '/';
			else
				break;
			if (op)
			{
				expr right = getFactor(lookup);
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

int main()
{
	char input[200];
	while (true)
	{
		cout << "输入表达式,输入q结束:\n" << ends;
			gets_s(input);
			{
				if (input[0] == 'q')
					return 0;
	
				char* stream = input;
				expr result = getExpression(stream);

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
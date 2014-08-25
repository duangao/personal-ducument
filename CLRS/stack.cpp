/*#include<iostream>
using namespace std;
template<class Type>
class stack
{
public:
	bool empty();
	Type& pop();
	void push(Type &elem);
	stack(int s) :size(s), top1(-1), top2(size){ array = new Type[size]; }
	void display();
private:
	int size;
	int top1;
	int top2;
	Type *array;
	Type& pop_1();
	Type& pop_2();
};
template<class Type>
void stack<Type>::display()
{
	cout << "stack1: " << endl;
	for (int i = 0; i <= top1; ++i)
		cout << array[i] << "	";
	cout << endl;
	if (top2 != size)
	{
		cout << "stack2: " << endl;
		for (int i = size - 1; i >= top2; --i)
			cout << array[i] << "	";
		cout << endl;
	}
}
template<class Type>
bool stack<Type>::empty()
{
	if (top1 == -1 && top2 == size)
		return true;
	else return false;
}
template<class Type>
Type& stack<Type>::pop_1()
{
	Type result = array[top1];
	--top1;
	return result;

}
template<class Type>
Type& stack<Type>::pop_2()
{
	Type result = array[top2];
	++top2;
	return result;
}
template<class Type>
Type& stack<Type>::pop()
{
	if (top1<size)
	{
		return	pop_1();
	}
	else if (top2 >= 0)
	{
		return	pop_2();
	}
	else
	{
		cout << "error!" << endl;
	}


}
template<class Type>
void stack<Type>::push(Type &elem)
{
	if (top2 - top1>1)
	{
		++top1;
		array[top1] = elem;
	}
	else
		cout << "error!" << endl;
}

int main()
{
	stack<int> s(5);
	int a = 3, b = 4, c = 6, d = 8, e = 9;
	s.push(a); s.push(b); s.push(c); s.push(d); s.push(e);
	s.display();
	s.pop();
	cout << s.pop() << endl;
	s.display();
	system("pause");
}
*/

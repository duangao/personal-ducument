/*#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &a)
{	
	for (vector<int>::size_type i = 0;i<a.size();i++)
		cout << a[i]<< "	";
	cout << endl;
}

vector<int>& countingSort(vector<int>& a, const int k,vector<int>& b)
{	
	int length = a.size();
	vector<int> c(k+1,0);
	b=vector<int>(length,0);
	
	//cout << length << endl;
	//display(a);
	for (vector<int>::size_type i = 0; i < length; ++i)
		++c[a[i]];
	
	for (vector<int>::size_type i = 1; i != k+1; ++i)
		c[i] += c[i - 1];
	
	for (vector<int>::size_type i = 1; i <= length;++i)
	{	
		int j = length - i;
		b[c[a[j]]-1] =a[j];	
		--(c[a[j]]);
	}
	
	
	return b;
}


int main()
{
	vector<int> a = { 2, 5, 3, 0, 2, 3, 0, 3 };
	vector<int> result;
	result=countingSort(a, 5, result);
	display(result);	
	system("pause");
}*/
//#include<iostream>
//using namespace std;

/*int* sum_binary_number(int a[],  int b[], int size)
{
	int *c = new int[size + 1];
	for (int k = 0; k < size+1;++k)
		c[k] = 0;

	for (int i = size - 1; i >= 0; --i)
	{
		if ((a[i]+b[i] == 1 && c[i+1]==0) || (a[i]+b[i]==0 && c[i+1]==1))
			c[i + 1] =1;
		else if ((a[i] + b[i] + c[i + 1] )== 0)
			c[i + 1] = 0;
		else if ((a[i] + b[i] == 2 && c[i + 1] == 0) || a[i] + b[i] == 1 && c[i + 1] == 1)
		{
			c[i + 1] = 0;
			c[i] = 1;
		}
		else if (a[i] + b[i] == 2 && c[i + 1] == 1)
		{
			c[i + 1] = 1;
			c[i] = 1;
		}
	}
	return c;
}*/
/*
int* sum_binary_number(int a[], int b[], int size)
{
	int *c = new int[size + 1];
	for (int k = 0; k < size + 1; ++k)
		c[k] = 0;

	for (int i = size - 1; i >= 0; --i)
	{
		int sum_binary = a[i] + b[i]+c[i+1];
		cout << sum_binary << endl;
		switch (sum_binary)
		{
		
			
		case 2:c[i] = 1;
		case 0:c[i + 1] = 0;
			break;
		
		case 3:c[i] = 1;
		case 1:c[i + 1] = 1;
			break;
		}
	}
	return c;
}
int main()
{
	const int size = 5;
	int a[size] = { 1,0,1,0,1 };
	int b[size] = { 1,1,1,1,1 };
	int *c = new int[size + 1];
	c = sum_binary_number(a, b, size);
	for (int i = 0; i < size + 1; ++i)
		cout << c[i];
	cout << endl;
	system("pause");
}*/
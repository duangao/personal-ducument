/*#include<iostream>
using namespace std;


int maxSubArray(int a[], int begin, int end)
{	
	int sum = 0;
	int i = 0;
	int maxSum = 0;
	for (int i = begin; i <= end; ++i)
	{	
		sum += a[i];
		if (sum > maxSum)
			maxSum = sum;
		cout << maxSum << endl;
		if (sum < 0)
			sum = 0;
	}
	
	return maxSum;
}


int main()
{
	const int SIZE = 13;
	int a[SIZE] = { -3, -15, 20, -3, -16, -23, 18, 20, -9, 12, -5, -22, 15 };
	int maxsubarray = maxSubArray(a, 0, 12);
	cout << maxsubarray << endl;
	system("pause");
}*/
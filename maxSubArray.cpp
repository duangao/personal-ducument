/*#include<iostream>
using namespace std;

int maxCrossSum(int a[], int begin, int mid, int end)
{
	int sumLeft = a[mid];
	int sumNow=0;
	for (int i = mid; i >= begin; --i)
	{
		sumNow += a[i];
		if (sumNow > sumLeft)
			sumLeft = sumNow;
	}

	int sumRight = a[mid + 1];
	sumNow = 0;
	for (int i = mid + 1; i <= end; ++i)
	{
		sumNow += a[i];
		if (sumNow > sumRight)
			sumRight = sumNow;
	}

	return sumLeft + sumRight;
}

int maxSubArray(int a[], int begin, int end)
{	
	if (begin == end)
		return a[begin]; 
	else
	{

		int mid = (begin + end) / 2;
		int leftSum = maxSubArray(a, begin, mid);
		int rightSum = maxSubArray(a, mid + 1, end);
		int crossSum = maxCrossSum(a, begin, mid, end);

		int sum;
		if (leftSum > rightSum)
			sum = leftSum;
		else sum = rightSum;
		if (sum < crossSum)
			sum = crossSum;

		return sum;
	}
}


int main()
{
	const int SIZE = 13;
	int a[SIZE] = { -3, -15, 20, -3, -16, -23, 18, 20, -9, 12, -5, -22, 15 };
	int maxsubarray = maxSubArray(a, 0, 12);
	cout << maxsubarray << endl;
	system("pause");
}*/
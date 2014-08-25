/*#include<iostream>
#include<windows.h>
using namespace std;
const int min_size =5;
void insert_sort(int *array, int ini, int ter)
{
	for (int i = 1; i <= ter; ++i)
	{
		int key = array[i];
		int j = i - 1;
		while (key < array[j] && j >= 0)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}
void display(int a[], int ini, int ter)
{
	for (int i = ini; i <= ter; ++i)
		cout << a[i] << "    ";
	cout << endl;
}
int partition(int *a, int begin, int end)
{
	int pivot = a[begin];
	int cur = begin + 1;
	int divid_location = begin;
	for (; cur <= end; ++cur)
	{
		if (a[cur] < pivot)
		{
			++divid_location;
			int temp = a[divid_location];
			a[divid_location] = a[cur];
			a[cur] = temp;
		}
	}
	a[begin] = a[divid_location];
	a[divid_location] = pivot;
	return divid_location;
}
void quick_sort(int *a, int begin, int end)
{
	if (end - begin > min_size)
	{
		int div = partition(a, begin, end);
		quick_sort(a, begin, div);
		int div_plus_1 = div + 1;
		quick_sort(a, div_plus_1, end);
	}
	insert_sort(a, begin, end);
}
int main()
{
	
	const int size = 10;
	int a[size] = { 8, 4, 3, 2, 1, 9, 7, 6, 5, 10 };
	
	DWORD dwStart = GetTickCount();//获取开始时间

	int begin = 0;
	int end = size - 1;
	quick_sort(a, begin, end);
	DWORD dwEnd = GetTickCount();  //获取结束时间
	DWORD dwTimes = dwEnd - dwStart; //程序运行时间
	cout << dwTimes << endl;
	display(a, begin,end);
	
	system("pause");
}*/
/*#include<iostream>
#include<windows.h>
using namespace std;
const int splice =2;
void display(int a[], int ini, int ter);
void insert_sort(int array[], int ini, int ter)
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
void merge(int a[], int ini, int mid, int ter)
{
	int size_former = mid - ini + 1;
	int size_latter = ter - mid;

	int* former = new int[size_former];
	int* latter = new int[size_latter];

	for (int i = 0; i < size_former; ++i)
		former[i] = a[i+ini];
	for (int i = 0; i < size_latter; ++i)
		latter[i] = a[mid +1+ i];


	int cur_former = 0;
	int cur_latter = 0;
	int cur_result = ini;

	while (cur_former < size_former && cur_latter < size_latter)
	{
		if (former[cur_former] <= latter[cur_latter])
			a[cur_result++] = former[cur_former++];
		else if (former[cur_former] > latter[cur_latter])
			a[cur_result++] = latter[cur_latter++];
	}
	if (cur_former == size_former)
	{
		for (; cur_latter < size_latter;)
			a[cur_result++] = latter[cur_latter++];
	}
	else if (cur_latter == size_latter)
	{
		for (; cur_former < size_former;)
			a[cur_result++] = former[cur_former++];
	}


}

void merge_sort(int a[], int ini, int ter)
{
	if (ter - ini>splice)
	{
		int mid = (ini + ter) / 2;
		merge_sort(a, ini, mid);
		merge_sort(a, mid + 1, ter);
		merge(a, ini, mid, ter);
	}
	else
		insert_sort(a, ini, ter);
}

void display(int a[], int ini, int ter)
{
for (int i = ini; i <= ter; ++i)
cout << a[i] << "	";
cout << endl;
}
int main()
{
	const int size = 100000;
	int a[size];
	for (int i = 0; i < size; i++)
		a[i] = size - i;

	DWORD dwStart = GetTickCount();//获取开始时间
	merge_sort(a, 0, size - 1);
	DWORD dwEnd = GetTickCount();  //获取结束时间
	DWORD dwTimes = dwEnd - dwStart; //程序运行时间
	cout << dwTimes << endl;
	//display(a, 0, size-1);

	system("pause");
}*/
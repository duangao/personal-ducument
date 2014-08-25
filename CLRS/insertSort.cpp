/*#include<iostream>
#include<windows.h>
using namespace std;
void insert_sort(int array[], int size)				//插入排序，按照递增序排列
{
	for (int i = 1; i < size; ++i)					//i指示的是当前待插入元素
	{
		int key = array[i];						//key记录当前带插入元素的值
		int j=i-1;								//array[0……i-1]为已经排序好的序列
		while (key < array[j] && j>=0)			//将大于key的元素挨个后移,若想要按照递减排列，将<改为>即可！
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j+1] = key;						//插入当前元素
		
	}
}
void display(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << array[i] << "	";
	cout << endl;
}
int main()
{	
	const int size = 100000;
	int a[size];
	for (int i = 0; i < size; i++)
		a[i] = size - i;

	DWORD dwStart = GetTickCount();//获取开始时间

	insert_sort(a,size);
	DWORD dwEnd = GetTickCount();  //获取结束时间
	DWORD dwTimes = dwEnd - dwStart; //程序运行时间
	cout << dwTimes << endl;
	//display(a, 0, size-1);

	system("pause");
}*/
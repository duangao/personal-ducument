/*#include<iostream>
using namespace std;
#define LEFT(i) (i<<1)+1			//因为C++中数组是从1开始计数，因此左右孩子节点、parent节点计算方法和算法导论有所区别！
#define RIGHT(i) (i<<1)+2
#define PARENT(i) (i-1)>>1

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void max_heapify(int a[], int length, int cur)
{	
	bool symbol = true;
	while (cur < length && symbol == true)
	{	
		int left = LEFT(cur);
		int right = RIGHT(cur);
		
		symbol = false;
		
		int largest = cur;
		if (left<length&&a[left] > a[cur])
			largest = left;
		if (right<length&&a[right] > a[largest])
			largest = right;
		if (largest != cur)
		{
			swap(a[cur], a[largest]);
			symbol = true;
			cur = largest;
		}
		
	}
}
void bulid_max_heap(int a[], int length)
{
	for (int i = (length - 1) / 2; i >= 0; --i)
		max_heapify(a, length, i);
	
}

void heapSort(int a[], int size)
{
	bulid_max_heap(a, size);
	int i = size - 1;
	while (i>=1)
	{
		
		swap(a[0], a[i]);
		max_heapify(a, i, 0);
		--i;
	}
}
void display(int a[], int size)
{
	for (int i = 0; i < size; ++i)
		cout << a[i] <<"	";
	cout << endl;
}



int main()
{	
	const int size = 10;
	
	int a[size] = {4,1,3,2,16,9,10,14,8,7};
	
	cout << "input result: \n";
	display(a, size);
	bulid_max_heap(a, size);
	cout << "max heap:\n";
	display(a, size); // 16,14,10,8,7,9,3,2,4,1
	
	heapSort(a, size);
	cout << "heapSort result: \n";
	display(a, size);
	
	system("pause");
	return 0;
}*/
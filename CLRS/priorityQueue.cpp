/*#include<iostream>
#include<vector>
using namespace std;
#define LEFT(i) (i<<1)+1			//因为C++中数组是从1开始计数，因此左右孩子节点、parent节点计算方法和算法导论有所区别！
#define RIGHT(i) (i<<1)+2
#define PARENT(i) (i-1)>>1


template<class Type>
class priorityQueue
{
private:
	vector<Type> heap;
	void max_heapify(int cur);
	void swap(Type &a, Type &b);
	void bulid_max_heap();
public:
	void heap_changed_value(int i,Type value);
	void insert(Type &elem);
	Type& maximum();
	priorityQueue(vector<Type> &a);
	priorityQueue() :heap(){}
	void display();
	//virtual ~priorityQueue();
};


template<class Type>
void priorityQueue<Type>::heap_changed_value(int i, Type value)
{	
	Type old_value = heap[i];
	heap[i] = value;
	if (value > old_value)
	{

		while (i > 0 && heap[PARENT(i)] < heap[i])
		{
			swap(heap[PARENT(i)], heap[i]);
			i = PARENT(i);
		}
	}
	else if (value < old_value)
	{
		max_heapify(i);
	}
}


template<class Type>
void priorityQueue<Type>::insert(Type &elem)
{
	heap.push_back(elem);
	int i = heap.size()-1;
	while (i>0 && heap[PARENT(i)] < heap[i])
	{
		swap(heap[PARENT(i)], heap[i]);
		i = PARENT(i);
	}
	
}


template<class Type>
Type& priorityQueue<Type>::maximum()
{
	return heap[0];
}


template<class Type>
priorityQueue<Type>::priorityQueue(vector<Type> &a)
{	
	heap = a;
	bulid_max_heap();
}


template<class Type>
void priorityQueue<Type>::swap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}


template<class Type>
void priorityQueue<Type>::max_heapify(int cur)
{
	bool symbol = true;
	int length = heap.size();
	while (cur < length && symbol == true)
	{
		int left = LEFT(cur);
		int right = RIGHT(cur);

		symbol = false;

		int largest = cur;
		if (left<length && heap[left] > heap[cur])
			largest = left;
		if (right<length && heap[right] > heap[largest])
			largest = right;
		if (largest != cur)
		{
			swap(heap[cur], heap[largest]);
			symbol = true;
			cur = largest;
		}

	}
}


template<class Type>
void priorityQueue<Type>::bulid_max_heap()
{	
	int length = heap.size();
	for (int i = (length - 1) / 2; i >= 0; --i)
		max_heapify(i);
}

template<class Type>
void priorityQueue<Type>::display()
{	
	cout << "this is the priority queue:\n";
	for (vector<Type>::iterator i = heap.begin(); i != heap.end(); ++i)
		cout << *i << "	";
	cout << endl;
}
int main()
{
	vector<int> array = { 4,1,3,2,16,9,10,14,8,7 };
	priorityQueue<int> pQ(array);
	cout<<"max value: "<<pQ.maximum()<<endl;
	pQ.display();

	pQ.heap_changed_value(1, 6);
	pQ.display();

	int elem = 20;
	pQ.insert(elem);
	pQ.display();

	
	system("pause");
	return 0;
}*/
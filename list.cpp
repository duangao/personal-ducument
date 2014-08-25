/*#include<iostream>
using namespace std;
template<class Type> class linkedlist;
template<class Type>
class node
{
	friend class linkedlist < Type >;
	template<class Type> friend  ostream& operator<<(ostream& os, linkedlist<Type>&list);
private:
	Type data;
	node<Type>* next;
public:
	node() :next(NULL), data(0){}
	node(const Type &elem) :data(elem), next(NULL){}

};

template<class Type>
class linkedlist
{
private:

	int size;
	node<Type>* head;
	node<Type>* find(node<Type> *begin, int size, Type &elem);
	node<Type> *search(node<Type> *begin, int size, Type &elem);
	void sort(node<Type> *begin);
	void copy(linkedlist<Type> &list1);
public:
	linkedlist();
	~linkedlist();
	int get_size()const { return size; }
	bool empty()const{ return size != 0; }
	Type & operator[](int location)const;
	node<Type>* get_head_node()const{ return head; }
	node<Type> *find(Type &elem){ return find(head->next, size, elem); }
	node<Type> *search(Type &elem){ return search(head->next, size, elem); }
	void insert_as_first_node(Type &elem);

	Type& remove(node<Type> *p);
	void sort(){ sort(head->next); }
	template<class Type> friend  ostream& operator<<(ostream& os, linkedlist<Type>&list);
	void merge(linkedlist<Type> &list1, linkedlist<Type> &list2);
	void reverse();

};
template<class Type>
linkedlist<Type>::linkedlist()
{
	head = new node<Type>;
	head->next = NULL;
	size = 0;


}

template<class Type>
linkedlist<Type>::~linkedlist()
{
	node<Type> *q = head->next;
	while (q != NULL)
	{
		node<Type> *p = q;
		q = q->next;
		delete p;
	}
}

template<class Type>
node<Type>*  linkedlist<Type>::find(node<Type> *begin, int size, Type &elem)
{
	int i = 1;
	for (node<Type>*p = begin; i <= size; i++, p = p->next)
	{
		if (p->data == elem)
			return p;
	}
	if (i > size)
		return NULL;
}

template<class Type>
node<Type>* linkedlist<Type>::search(node<Type> *begin, int size, Type &elem)
{
	find(begin, size, elem);
}

template<class Type>
ostream& operator<<(ostream& os, linkedlist<Type>&list)
{
	node<Type>*p;
	for (p = list.head->next; p != NULL; p = p->next)
		os << p->data << " ";
	return os;
}

template<class Type>
void linkedlist<Type>::insert_as_first_node(Type &elem)
{
	node<Type> *p = new node<Type>(elem);
	p->next = head->next;
	head->next = p;
	++size;
}

template<class Type>
Type& linkedlist<Type>::remove(node<Type> *p)
{
	node<Type>*q;
	for (q = head->next; q->next != p; q = q->next)
	{
	}
	q->next = p->next->next;
	Type d = p->data;
	delete p;
	--size;
	return d;
}

template<class Type>
void linkedlist<Type>::sort(node<Type> *begin)
{
	for (node<Type> *p = begin; p->next != NULL; p = p->next)
	{
		node<Type> *min = p;

		for (node<Type>*q = p->next; q != NULL; q = q->next)
		if (min->data > q->data)
			min = q;

		Type temp = p->data;
		p->data = min->data;
		min->data = temp;
	}
}

template<class Type>
void linkedlist<Type>::copy(linkedlist<Type> &list1)
{
	node<Type> *p = list1.head->next;
	node<Type> *tail = head;
	while (p != NULL)
	{
		node<Type> *new_node = new node < Type >(p->data);
		tail->next = new_node;
		tail = new_node;
		p = p->next;
	}
}

template<class Type>
void linkedlist<Type>::merge(linkedlist<Type> &list1, linkedlist<Type> &list2)
{
	linkedlist<Type> copy_list1;
	copy_list1.copy(list1);
	linkedlist<Type> copy_list2;
	copy_list2.copy(list2);

	node<Type> *p1 = list1.head->next;
	node<Type> *p2 = list2.head->next;
	node<Type> *tail = head;

	while (p1 && p2)
	{
		node<Type> *new_node = new node < Type >;
		tail->next = new_node;
		tail = new_node;
		if (p1->data < p2->data)
		{
			tail->data = p1->data;
			p1 = p1->next;
		}
		else if (p2->data < p1->data)
		{
			tail->data = p2->data;
			p2 = p2->next;
		}
		else if (p2->data == p1->data)
		{
			tail->data = p1->data;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if (p1 == NULL)
		tail->next = p2;
	else if (p2 == NULL)
		tail->next = p1;
}
template<class Type>
void linkedlist<Type>::reverse()
{	
	if (head->next == NULL)
		return;
	node<Type>* pre = head->next;
	node<Type>* cur = pre->next;
	pre->next = NULL;
	delete head;
	
	for (; cur != NULL; )
	{	
		
		node<Type> *post = cur->next;
		
		cur->next = pre;
		pre = cur;
		cur = post;
		
	}
	head = new node<Type>;
	head->next = pre;
	

}
int main()
{
	linkedlist < int >  list1;
	//cout << "is empty?" << list1.empty() << endl;
	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8;
	list1.insert_as_first_node(a); list1.insert_as_first_node(b); list1.insert_as_first_node(c); list1.insert_as_first_node(d); list1.insert_as_first_node(e); list1.insert_as_first_node(f); list1.insert_as_first_node(g); list1.insert_as_first_node(h);
	cout << list1 << endl;
	list1.reverse();
	cout << list1 << endl;
	//cout <<"size: "<< list1.get_size() << endl;
	//cout <<"this is the linkedlist: "<< list1 << endl;
	//cout <<"address:"<< list1.find(a) << endl;
	//cout<<"address: "<<list1.find(h)<<endl;
	/*int i = 10, j = 11, k = 13, l = 14, m = 15, n = 16;
	linkedlist<int> list2;
	list2.insert_as_first_node(i); list2.insert_as_first_node(j); list2.insert_as_first_node(k); list2.insert_as_first_node(l); list2.insert_as_first_node(m); list2.insert_as_first_node(n);
	list1.sort();
	list2.sort();
	cout << "this is the linkedlist1: " << list1 << endl;
	cout << "this is the linkedlist2: " << list2 << endl;
	linkedlist<int> list3;
	list3.merge(list1, list2);
	cout << "this is the linkedlist3: " << list3 << endl;*/
	//system("pause");
	//return 0;
//}*/

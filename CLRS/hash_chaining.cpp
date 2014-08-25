/*#include<iostream>
#include<vector>

using namespace std;
const int LENGTH = 4;

template<class type_key, class type_elem> class hash_table;

template<class type_key, class type_elem>
class hash_node
{
	friend class hash_table<type_key,type_elem>;
private:
	type_key key;
	type_elem value;
	hash_node* next;
	hash_node* pre;
public:
	hash_node() :key(0), value(0), next(NULL),pre(NULL){}
	hash_node(type_key& k, type_elem &v) :key(k), value(v), next(NULL),pre(NULL){}
	hash_node(hash_node<type_key, type_elem> &x) :next(NULL), pre(NULL){ key = x.key; value = x.value; }
	friend ostream& operator<< <type_key,type_elem>(ostream& os, hash_table<type_key, type_elem>&h);

};



template<class type_key, class type_elem>
class hash_table
{
private:
	vector<hash_node<type_key, type_elem>*> hash_;
	int length;
	int hash_func(int k);
public:
	hash_table();

	hash_table(hash_table<type_key, type_elem> &h);
	virtual ~hash_table();

	void insert_(hash_node<type_key, type_elem>* x);
	void delete_(hash_node<type_key, type_elem >*x);
	hash_node<type_key, type_elem>* search(type_key &k);
	friend ostream& operator<< <type_key, type_elem>(ostream& os, hash_table<type_key, type_elem>&h);
};

template<class type_key, class type_elem>
int hash_table<type_key, type_elem>::hash_func(int k)
{
	return k % length;
}

template<class type_key, class type_elem>
hash_table<type_key, type_elem>::hash_table()
{	
	length = LENGTH;
	hash_ = vector<hash_node<type_key, type_elem>*>(length, NULL);
	
}


template<class type_key, class type_elem>
hash_table<type_key, type_elem>::hash_table(hash_table<type_key, type_elem> &h)
{
	hash_ = h.hash_;
	length = h.length;
}


template<class type_key, class type_elem>
hash_table<type_key, type_elem>::~hash_table()
{

}


template<class type_key, class type_elem>
void hash_table<type_key, type_elem>::insert_(hash_node<type_key, type_elem>* x)
{

	hash_node<type_key, type_elem> *p = search(x->key);
	if (p != NULL)
	{
		cerr << "the node is already exist!" << endl;
		return;
	}
	else
	{
		int location = hash_func(x->key);
		p = hash_[location];
		if (p == NULL)
		{
			p = new hash_node<type_key, type_elem>(*x);
		}
		else
		{
			hash_node<type_key, type_elem> *q = new hash_node<type_key, type_elem>(*x);
			p->next = q;
			q->pre = p;
		}

	}
	
}


template<class type_key, class type_elem>
void hash_table<type_key, type_elem>::delete_(hash_node<type_key, type_elem> *x)
{
	int location = hash_func(x->key);
	hash_node<type_key, type_elem> *p = search(x->key);
	if (p == NULL)
	{
		cout << "don't exist this node,so can not delete it!" << endl;
		return;
	}
	else
	{
		if (p->next == NULL)
		{
			hash_.erase(location);
		}
		else
		{
			
			hash_node<type_key, type_elem> *q = p->pre;
			q->next = p->next;
			delete p;
		}
	}
}


template<class type_key, class type_elem>
hash_node<type_key,type_elem>* hash_table<type_key, type_elem>::search(type_key &k)
{
	int location = hash_func(k);
	hash_node<type_key, type_elem>* p = hash_[location];


	while (p->key != k && p!=NULL)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		cerr << "can not search it!" << endl;
		return NULL;
	}
	else
	{
		return p;
	}

}

template<class type_key,class type_elem>
ostream& operator<<(ostream& os, hash_table<type_key, type_elem> &h)
{
	for (vector<hash_node<type_key, type_elem>*>::size_type i = 0; i < h.hash_.size(); ++i)
	{
		for (hash_node<type_key, type_elem> *p = h.hash_[i]; p != NULL; p = p->next)
			os << p->key << ":" << p->value << "		";
		os << endl;
	}
	return os;

}

int main()
{	
	hash_table<int, int> hash;
	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8, i = 9, j = 10;
	hash_node<int, int> n1(a, b); hash_node<int, int> n2(b, c); hash_node<int, int> n3(c, d); hash_node<int, int> n4(d, e); hash_node<int, int> n5(e, f); hash_node<int, int> n6(f, g); hash_node<int, int> n7(g, h);
	hash.insert_(&n1); hash.insert_(&n2); hash.insert_(&n3); hash.insert_(&n4); hash.insert_(&n5); hash.insert_(&n6); hash.insert_(&n7);
	
	system("pause");
	return 0;
}*/
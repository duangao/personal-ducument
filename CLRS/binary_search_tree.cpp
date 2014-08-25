#include<iostream>
using namespace std;

//结点类
template<typename T>
class TreeNode
{
	//声明为二叉搜索树的友元类
	template<class T> friend class BinarySearchTree;
	//方便<<操作符访问结点成员
	template<typename T> friend ostream& operator<<(ostream &os, BinarySearchTree<T>&BST);

private:
	T value;
	TreeNode<T>* lchild;
	TreeNode<T>* rchild;
	TreeNode<T>* parent;//带parent结点要方便的多

	TreeNode<T>* _increase();//自增，即中序下的后继
	TreeNode<T>* _decrease();//自减，即中序下的前驱
public:
	//三个构造函数
	TreeNode() :value(0), lchild(NULL), rchild(NULL), parent(NULL){}
	TreeNode(T v) :value(v), lchild(NULL), rchild(NULL), parent(NULL){}
	TreeNode(TreeNode<T> &node) :value(node.value), lchild(node.lchild), rchild(node.rchild), parent(node.parent){}
	virtual ~TreeNode(){} //析构函数设置为虚函数
	void _test_display()  //此函数只是测试使用，应该删去
	{
		cout << "value: " << this->value << "     ";
		if (this->lchild != NULL)
			cout << "lchild: " << this->lchild->value << "  ";
		else  cout << "lchild: NULL" << "  ";
		if (this->rchild != NULL)
			cout << "rchild: " << this->rchild->value << "  ";
		else  cout << "rchild: NULL" << "  ";
		if (this->parent != NULL)
			cout << "parent: " << this->parent->value << "  ";
		else  cout << "parent: NULL" << "  ";
		cout << endl;
	}

};

//二叉搜索树类
template<typename T>
class BinarySearchTree
{

private:
	TreeNode<T> *root; //根节点
	int size;    //结点数量

	TreeNode<T>* _copy(TreeNode<T> *node, TreeNode<T>* q); //私有函数，node表示复制以node为根节点的树，参数q实际上指向node的父节点，是实现的小技巧
	TreeNode<T>* _mininum(TreeNode<T>* node);             //私有函数，找到以node为根节点的树中的最小结点
	TreeNode<T>* _maxinum(TreeNode<T>* node);

	virtual TreeNode<T>* _insert(T& value, TreeNode<T>* node);//私有函数，用于实现Insert操作
	virtual void _delete(TreeNode<T>* _delete_node, TreeNode<T>* node);//私有函数，用于实现Delete操作
	TreeNode<T>* _search(T& value, TreeNode<T>* node);               //私有函数，用于实现Search操作
	virtual void _init(T* array, int length);                //通过数组初始化二叉搜索树
	virtual void _clear(TreeNode<T>* node);                   //清空node为根节点的树



public:
	//构造和析构函数
	BinarySearchTree() :root(NULL), size(0){}
	BinarySearchTree(T* array, int length)    { _init(array, length); }
	BinarySearchTree(BinarySearchTree<T> &tree){ root = _copy(tree.root, NULL); size = tree.size; }
	virtual ~BinarySearchTree() { _clear(root); size = 0; }
	//赋值操作符的重载
	virtual BinarySearchTree<T>& operator=(BinarySearchTree<T> &tree){ _clear(root); root = _copy(tree.root, NULL);  size = tree.size; return *this; }
	//判断树是否为空
	bool isEmpty() { return size == 0; }
	//返回树中结点个数
	int Size()   { return size; }
	//基本操作，Insert、Delete、Search
	virtual TreeNode<T>*  Insert(T& value){ return _insert(value, root); }
	virtual void Delete(TreeNode<T>* node){ return _delete(node, root); }
	TreeNode<T>* Search(T& value){ return _search(value, root); }

	//返回树中value最大和最小的结点的value
	T& mininum(){ return _mininum(root)->value; }
	T& maxinum(){ return _maxinum(root)->value; }
	//返回某个节点的parent
	TreeNode<T>* parent(TreeNode<T> *node){ return node->parent; }
	//<<操作符必须设置为友元，不可以是成员
	template<typename T> friend ostream& operator<<(ostream &os, BinarySearchTree<T>&BST);

	//一个测试函数
	void __test(){ cout << "测试_ decrease" << --(this->root->rchild->lchild->lchild)->value << endl; };

};

template<typename T>
TreeNode<T>* BinarySearchTree<T>::_copy(TreeNode<T>* node, TreeNode<T>* q)
{
	//这里q保存node的父节点，调用时初始化为NULL（root的parent为NULL）

	if (node == NULL)
		return NULL;

	TreeNode<T>* p = new TreeNode<T>(node->value);
	p->parent = q;
	p->lchild = _copy(node->lchild, p);//递归复制
	p->rchild = _copy(node->rchild, p);
	return p;
}


template<typename T>
TreeNode<T>* BinarySearchTree<T>::_mininum(TreeNode<T>* node)//最左端结点为最小
{
	TreeNode<T> * p = node;
	TreeNode<T>* q = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->lchild;
	}
	return q;
}
template<typename T>
TreeNode<T>* BinarySearchTree<T>::_maxinum(TreeNode<T>* node)//最右端结点为最大
{
	TreeNode<T>* p = node;
	TreeNode<T>* q = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->rchild;
	}
	return q;
}
template<typename T>
TreeNode<T>* TreeNode<T>::_increase()
{
	if (this == NULL)
		return NULL;
	else
	{
		if (this->rchild != NULL)         //当前结点如果有右孩子，则后继为右子树中最小的结点
		{
			TreeNode<T> * p = this->rchild;
			TreeNode<T>* q = p;
			while (p != NULL)
			{
				q = p;
				p = p->lchild;
			}

			return q;
		}
		else                                        //否则，则向上回溯，直到第一次出现 q 是 p 的左孩子结点为止
		{
			TreeNode<T> *q = this;
			TreeNode<T> *p = this->parent;
			//cout<<"parent:" << p->value << endl;
			//cout <<"cur:   "<< q->value << endl;
			while (q != p->lchild)
			{
				q = p;
				p = p->parent;
				if (p == NULL)
					break;
			}
			//cout << "parent: " << p->value << endl;

			return p;
		}
	}

}
template<typename T>
TreeNode<T>* TreeNode<T>::_decrease()
{
	if (this == NULL)
		return NULL;
	else
	{
		if (this->lchild != NULL)                 //当前结点如果有左孩子，则后继为右子树中最大的结点
		{
			TreeNode<T> *p = this->lchild;
			TreeNode<T> *q = p;
			while (p != NULL)
			{
				q = p;
				p = p->rchild;
			}
			return q;
		}
		else                                        //否则，则向上回溯，直到第一次出现 q 是 p 的右孩子结点为止
		{
			TreeNode<T> *q = this;
			TreeNode<T> *p = this->parent;
			while (q != p->rchild)
			{
				q = p;
				p = p->parent;
				if (p == NULL)
					break;
			}
			return p;
		}
	}

}

template<typename T>
TreeNode<T>*  BinarySearchTree<T>::_insert(T& value, TreeNode<T>* node)  //insert操作的返回值为指向插入结点的指针
{
	TreeNode<T> *p = new TreeNode<T>(value);
	TreeNode<T> *parent_node = NULL;

	while (node != NULL)
	{
		if (p->value < node->value)
		{
			parent_node = node;
			node = node->lchild;
		}
		else
		{
			parent_node = node;
			node = node->rchild;
		}
	}
	// 找到待插入结点parent_node
	if (parent_node != NULL)
	{
		p->parent = parent_node;
		if (p->value < parent_node->value)
		{
			parent_node->lchild = p;
		}
		else
		{
			parent_node->rchild = p;
		}
	}
	else   //当前树为空
	{
		root = p;
	}
	return p;

}
template<typename T>
void BinarySearchTree<T>::_delete(TreeNode<T>* _delete_node, TreeNode<T>* node)
{
	TreeNode<T> *y, *x;
	if (_delete_node->lchild == NULL || _delete_node->rchild == NULL)  //如果待删除结点有一个孩子或者没有孩子，那么要被移除的结点就是它自己
		y = _delete_node;
	else y = _delete_node->_increase();        //如果有两个结点，那么要移除的结点就是它的后继（然后把它的后继的value赋值给它）

	if (y->lchild != NULL)
		x = y->lchild;    //如果y的左孩子不空的话，赋值给x
	else x = y->rchild;        //否则，无论是右孩子空不空，都赋值给x

	TreeNode<T> *parent_of_y = parent(y);

	if (y != _delete_node)
	{
		_delete_node->value = y->value;
		x->parent = parent_of_y;
		if (y == parent_of_y->lchild)
			parent_of_y->lchild = x;
		else
			parent_of_y->rchild = x;
		delete y;
	}
	else
	{
		x->parent = parent_of_y;
		if (parent_of_y == NULL)
		{
			node = x;

			delete y;
		}
		else
		{
			if (parent_of_y->lchild == y)
				parent_of_y->lchild = x;
			else
				parent_of_y->rchild = x;
			delete y;
		}
	}

}
template<typename T>
TreeNode<T>* BinarySearchTree<T>::_search(T& value, TreeNode<T>* node)  //search是其最擅长的操作，返回值为找到结点的指针
{
	TreeNode<T>* p = node;
	while (p != NULL)
	{
		if (value < p->value)
			p = p->lchild;
		else if (value > p->value)
			p = p->rchild;
		else return p;
	}
	return NULL;
}
template<typename T>
void BinarySearchTree<T>::_init(T* array, int length)     //反复调用insert操作来初始化，并且增大size
{

	for (int i = 0; i < length; ++i)
	{
		_insert(array[i], root);
		++size;
	}
}

template<typename T>
void BinarySearchTree<T>::_clear(TreeNode<T>* node)    //递归调用来删除
{
	if (node == NULL)
		return;

	TreeNode<T>* p = node->lchild;
	TreeNode<T>* q = node->rchild;
	delete node;
	_clear(p);
	_clear(q);
}

template<typename T>
ostream& operator<<(ostream &os, BinarySearchTree<T>& BST)    //这里其实是一个迭代版（不用辅助stack）的方法
{
	TreeNode<T>* node = BST.root;
	while (true)
	{
		if (node->lchild != NULL)        //一直访问到当前最左边结点
			node = node->lchild;
		else
		{
			os << node->value << "  ";  //输出当前结点的value
			while (node->rchild == NULL)          //如果无右孩子，则访问其后继，注意这里是循环
			{

				node = node->_increase();

				if (node != NULL)
					os << node->value << "  ";
				else break;
			}
			if (node != NULL)                //如果有右孩子，访问其右孩子（这里是一个尾递归优化而来的迭代，容易理解）
			{
				node = node->rchild;
			}
			else break;

		}

	}
	return os;
}
int main()
{
	const int length = 9;
	int array[length] = { 13, 9, 17, 5, 12, 15, 18, 2, 19 };
	//检测_init    _insert    operator<<    _increase
	BinarySearchTree<int> BST(array, length);
	cout << "BST: " << BST << endl;
	int v = 14;
	BST.Insert(v);
	cout << "BST insert one node with value 14: " << BST << endl;


	//检测_copy,okay
	BinarySearchTree<int> Bst(BST);
	cout << Bst << endl;

	//检测operator=,okay
	BinarySearchTree<int> bst, bsT;
	bsT = bst = Bst;
	cout << "!" << bst << endl;
	cout << "!" << bsT << endl;

	//检测_mininum  _maxinum,okay
	cout << "maxinum" << BST.maxinum() << endl;
	cout << "mininum" << BST.mininum() << endl;

	//检测 _decrease,okay
	BST.__test();

	//检测_search,okay
	TreeNode<int> *p = BST.Search(array[0]);
	p->_test_display();
	p = BST.Search(array[7]);
	p->_test_display();
	p = BST.Search(array[8]);
	p->_test_display();


	//检测_delete,okay
	p = BST.Search(array[2]);
	BST.Delete(p);
	cout << "delete the node with value 17" << endl;
	cout << BST << endl;

	//测试size 
	cout << "BST size: " << BST.Size() << endl;
	cout << "bsT size: " << bsT.Size() << endl;
	system("pause");

}
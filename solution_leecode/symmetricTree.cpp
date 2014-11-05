#include <iostream>
using namespace std;
/*
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode* insert_left(TreeNode *cur,int val)
{
	TreeNode *temp=new TreeNode(val);
	if(cur != NULL)
		cur->left=temp;
	return temp;
}
TreeNode* insert_right(TreeNode *cur,int val)
{
	TreeNode *temp=new TreeNode(val);
	if(cur != NULL)
		cur->right=temp;
	return temp;
}*/

class Solution{
    TreeNode *i;
    TreeNode *j;
public:
    bool isSymmetric(TreeNode *root)
    {
		//约定空树是对称的
		if(root==NULL)
			return true;
		else
			return isEqual(root->left,root->right);
    }
	//判断是否对称，应该是有两个指针去迭代的，因此写一个两个指针参数的判断函数，递归的进行判断
	bool isEqual(TreeNode *a,TreeNode *b)
	{
		//当前两个结点均为空，则这一步的判断上是对称的
		if(a==NULL && b==NULL)
			return true;
		//只有一个为空，另一个不为空，显然不对称
		else if(a==NULL || b==NULL)
		    return false;
		//如果当前的两个结点非空且相等，则递归的判断他们的左右-右左结点
		if(a->val == b->val)
			return isEqual(a->left,b->right)&&isEqual(a->right,b->left);
		else return false;
	}
};
/*
int main()
{
	TreeNode *root=new TreeNode(1);
	root->left=insert_left(root,2);
	root->right=insert_right(root,3);
	root->left->left=insert_left(root->left,3);
	root->right->left=insert_left(root->right,2);
	Solution a;
	cout<<a.isSymmetric(root)<<endl;
}*/

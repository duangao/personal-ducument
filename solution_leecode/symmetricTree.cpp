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
		if(root==NULL)
			return true;
		else
			return isEqual(root->left,root->right);
    }
	bool isEqual(TreeNode *a,TreeNode *b)
	{
		if(a==NULL && b==NULL)
			return true;
		else if(a==NULL || b==NULL)
		    return false;
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

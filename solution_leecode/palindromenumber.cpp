class Solution { 
public:
	//产生逆序数字的一个好方法，在不断取余、整除的过程中构造回文数字；约定负数不是回文数字
    bool isPalindrome(int x) { 
        int result=0; 
		//注意下面会修改x的值，所以提前保留
        int copy_x=x; 
        if(x<0) 
            return false; 
        while(x!=0) 
        { 
            result=result*10+x%10; 
            x/=10; 
        } 
        if(result==copy_x) 
        return true; 
        else return false; 
    } 
};

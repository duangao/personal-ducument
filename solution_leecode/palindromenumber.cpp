class Solution { 
public: 
    bool isPalindrome(int x) { 
        int result=0; 
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

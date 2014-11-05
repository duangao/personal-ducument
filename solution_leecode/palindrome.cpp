#include<string>
#include <iostream>
using namespace std;
class Solution { 
public: 
    bool isPalindrome(string s) { 
    //清空string内部所有不是字母的内容，要注意的是erase删除后返回其下一个元素，利用这点来连续删除，若使用i++则会导致运行时错误
    for(string::iterator i=s.begin();i<s.end();) 
    { 
        if(!isalnum(*i)) 
        { 
            i=s.erase(i); 
        } 
		else i++;
    } 
	//cout<<s<<endl;
	//空串约定为真
    if(s.size()==0) 
     return true; 
	//下面是一段朴素的判断回文字符串的例子，注意到大小写无关，所以调用了tolower函数
    string::iterator start = s.begin(); 
	string::iterator end = start+s.size()-1; 
     
	while (start <= end&&start!=s.end()&&end>s.begin()) 
	{ 
	    
		if (tolower(*start) == tolower(*end)) 
		{ 
			start++; 
			end--; 
		} 
		else 
			return false; 
	} 
	return true; 
    }
};

int main()
{
	string input;

	//cin>>input;
	input="......a.....";
	Solution s;
	cout<<s.isPalindrome(input)<<endl;

}

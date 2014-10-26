#include<string>
#include <iostream>
using namespace std;
class Solution { 
public: 
    bool isPalindrome(string s) { 
     
    for(string::iterator i=s.begin();i<s.end();) 
    { 
        if(!isalnum(*i)) 
        { 
            i=s.erase(i); 
        } 
		else i++;
    } 
	cout<<s<<endl;
    if(s.size()==0) 
     return true; 
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

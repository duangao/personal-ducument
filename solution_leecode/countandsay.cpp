#include <iostream>
using namespace std;

class Solution{
	string result;
	public:
		void generate(string s,string &result)
		{
			result=string();
			string::iterator i=s.begin();
			while(i != s.end())
			{
				char cur=*i;
				int count=1;
				i++;
				while(i != s.end() && *i == cur)
				{
					count++;
					i++;
				}
				result.push_back(count+'0');
				result.push_back(cur);

			}

		}
		string countAndSay(int n){

			for(int i=1;i<n;i++)
			{
				
				generate(result,result);
			}
			return result;
		}
Solution():result("1"){}
};

int main()
{
	int input;
	cin>>input;
	Solution s;
	string result=s.countAndSay(input);
	cout<<"result"<<result<<endl;
}

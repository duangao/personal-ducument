#include <iostream>
using namespace std;

class Solution{
	string result;
	public:
	//根据数组前一个数，count and say构造出后一个数
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
		//n相当于数组的下标，n是几就调用上面的函数几次，这样就反复调用，每次都以前一个为参数，得到答案
		string countAndSay(int n){

			for(int i=1;i<n;i++)
			{
				
				generate(result,result);
			}
			return result;
		}
};

int main()
{
	int input;
	cin>>input;
	Solution s;
	string result=s.countAndSay(input);
	cout<<"result"<<result<<endl;
}

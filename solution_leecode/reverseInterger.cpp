#include<iostream>
using namespace std;
class Solution
{
	public: 
		int reverse(int x){
		int result=0;
			while(x!=0)
			{
				result=result*10+x%10;
				x/=10;
			}
			return result;
		}
};

int main()
{
	Solution s;
	int x;
	cin>>x;
	cout<<"reverse: "<<s.reverse(x)<<endl;
}

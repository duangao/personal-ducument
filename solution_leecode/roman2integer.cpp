#include<iostream>
#include<vector>
#include<string>
using namespace std;
/* I:1 ; V-5;X-10;L-50;C-100;D-500;M-1000*/
class Solution{
	vector<string> tokens;
	vector<char> token_value;
	public:
	/*divide the string into some tokens,every token including same char*/
	void token(string s)
	{
		string::iterator i=s.begin();
		string::iterator j=s.begin();

		while(i!=s.end())
		{
			char cur=*i;
			token_value.push_back(cur);
			while(*i == cur){
				i++;
			}

			string temp(j,i);
			tokens.push_back(temp);
			j=i;
		}
	}
	/*比较相邻字母的大小*/
	bool lower(char a,char b)
	{
		if((a=='I' && b!='I')||(a=='V' && b!='I'&&b!='V') || (a=='X'&&b!='I'&&b!='V'&&b!='X')|| \
				(a=='L'&&b!='I'&&b!='V'&&b!='X'&&b!='L')||(a=='C' && (b=='D' || b=='M')) || (a=='D'&&b=='M'))
			return true;
		else return false;
	}
	int romanToInt(string s){
		token(s);
		int result=0;
		vector<int> res;
		/*将上述tokens转为一个int数组*/
		for(vector<string>::iterator i=tokens.begin();i!=tokens.end();i++)
		{
			string temp=*i;
			int temp_value=0;
			char cur=temp[0];
			int len=temp.size();
			for(int i=0;i<len;i++)
			{
				switch(cur)
				{
					case 'I':temp_value++;break;
					case 'V':temp_value+=5;break;
					case 'X':temp_value+=10;break;
					case 'L':temp_value+=50;break;
					case 'C':temp_value+=100;break;
					case 'D':temp_value+=500;break;
					case 'M':temp_value+=1000;break;
					default:break;
				}

			}
			res.push_back(temp_value);

		}
		result=res[res.size()-1];
		for(int i=token_value.size()-2;i>=0;i--)
		{
			if(lower(token_value[i],token_value[i+1])){
				result-=res[i];
			}
			else{
				result+=res[i];
			}
			cout<<result<<endl;
		}
		return result;
	}
};

int main()
{
	string str;
	cin>>str;
	Solution s;
	cout<<s.romanToInt(str)<<endl;

	return 0;
}

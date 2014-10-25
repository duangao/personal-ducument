#include<iostream>
#include<cstring>
#include<list>
#include<stack>
using namespace std;

typedef list<int> state_set;
const int INPUT_SYMBOL=3;
const int NFA_STATE=11;


bool Is(char* &stream,const char *test)
{
	int len=strlen(test);
	char *lookup=stream;
	while(*lookup == ' ')
		++lookup;
	if(strncmp(lookup,test,len)==0)
	{
		stream=lookup+len;
		return true;
	}
	else return false;
}

state_set move[NFA_STATE][INPUT_SYMBOL];

bool alreadyOn[NFA_STATE]={0};

stack<int> old_state;
stack<int> new_state;

void addState(int s)
{
	old_state.push
}
int main()
{
	return 0;
}



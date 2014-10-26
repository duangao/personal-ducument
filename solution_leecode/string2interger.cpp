class Solution {
	public:
		int bit_length(int n)	{
			int l=0;
			while(n!=0){
				l++;
				n/=10;
			}
			return l;
		}
	int atoi(const char *str){
	    if(*str=='\0') return 0;
		while(isspace(*str) || *str-'0' ==0 )str++;
		int number=0;
		bool times_minus=false;
		bool symbol=false;
		bool of=false;
		while(*str!='\0'){
			if(*str=='-')	{
			    if(((*(str+1)=='\0' )&&number!=0)|| !isdigit(*(str+1))){
			        symbol=true;
			        break;
			    }
			    times_minus=true;
			}
			else if(*str=='+'){
			     if(((*(str+1)=='\0')&&number!=0) || !isdigit(*(str+1))){
			         symbol=true;
			         break;
			         
			     }
			  }
			else if(isdigit(*str)){   
			    if(*str-'0'==0 && number==0)
				{}
			    else{
				    int num_copy=number;
				    number=number*10+*str-'0';
				    if(bit_length(number)==bit_length(num_copy)){
				    	of=true;
			    	}
			    }
			    
			}
			else 
			    break;
			str++;
		}	
	
		if(times_minus==true)
			number*=-1;
				    
		if (( of&&times_minus==true )|| (number>0 && times_minus==true))
			number=-2147483648;
		else if((of &&times_minus==false)|| (number<0 && times_minus==false))
			number=2147483647;
			
		if(symbol)
		    return 0;
        else return number;
	}
};

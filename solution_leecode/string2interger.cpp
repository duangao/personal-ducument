class Solution {
	public:
		//计算一个整数的位数，在溢出判断中使用
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
		// 将开头的空白字符和0去掉
		while(isspace(*str) || *str-'0' ==0 )str++;
		int number=0;
		bool times_minus=false;//是否是负数
		bool symbol=false; //是否违法
		bool of=false;  //是否溢出
		while(*str!='\0'){
			//+号处理
			if(*str=='-')	{
			    if(((*(str+1)=='\0' )&&number!=0)|| !isdigit(*(str+1))){
			        symbol=true;
			        break;
			    }
			    times_minus=true;
			}
			//-号处理
			else if(*str=='+'){
			     if(((*(str+1)=='\0')&&number!=0) || !isdigit(*(str+1))){
			         symbol=true;
			         break;
			         
			     }
			  }
			//数字处理
			else if(isdigit(*str)){   
			    if(*str-'0'==0 && number==0)
				{}
			    else{
				    int num_copy=number;
				    number=number*10+*str-'0';
					//溢出判断
				    if(bit_length(number)==bit_length(num_copy)){
				    	of=true;
			    	}
			    }
			    
			}
			//其他字符处理
			else 
			    break;

			str++;
		}	
	
		if(times_minus==true)
			number*=-1;
		//负溢出		    
		if (( of&&times_minus==true )|| (number>0 && times_minus==true))
			number=-2147483648;
		//正溢出
		else if((of &&times_minus==false)|| (number<0 && times_minus==false))
			number=2147483647;
			
		if(symbol)
		    return 0;
        else return number;
	}
};

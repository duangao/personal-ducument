/*需要说明的是 此例由于是区间，因此是有两个数构成的对，这里采用了引用形参返回的方法，也可以应用STL中的pair类型，方便的处理区间，也可以很容易的返回两个ini ter*/
/*#include<iostream>
#include<ctime>
using namespace std;
#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a
class Interval
{
public:
    double leftbound;
    double rightbound;
    Interval(int a, int b) :leftbound(a), rightbound(b){}
    Interval(Interval &i){ leftbound = i.leftbound;rightbound=i.rightbound; }
    Interval(){}
};
void swap(Interval &a, Interval &b)
{
    Interval temp = a;
    a = b;
    b = temp;
    
}
void display(Interval a[], int begin, int end)
{
    for (int i = begin; i <= end; ++i)
        cout << "[" << a[i].leftbound << "," << a[i].rightbound << "]" << ",";
    cout << endl;
}
pair<int, int>& partition(Interval a[], int begin, int end)
{
    
    Interval pivot = a[begin];        //主元区间
   int ini = begin;
   int ter = end+1;            //注意，这里ter从数组外部开始
    
    int cur = begin + 1;
    while (cur < ter && cur<end)
    {
        if (a[cur].rightbound <= pivot.leftbound && ini<end)        //小于主元区间
        {
            ++ini;
            swap(a[cur], a[ini]);
            ++cur;
            //cout << "1: ";
            //display(a, begin, end);
        }
        else if (a[cur].leftbound >= pivot.rightbound && ter>begin) //大于主元区间
        {
            --ter;
            swap(a[cur], a[ter]);
            //cout << "2: ";
            //display(a, begin, end);
            
        }
        else            //和主元区间相等， 所以取交集作为新的主元
        {
            pivot.leftbound = max(pivot.leftbound, a[cur].leftbound);
            pivot.rightbound = min(pivot.rightbound, a[cur].rightbound);
            //cout << "pivot: " << pivot.leftbound<<" ,"<<pivot.rightbound << endl;
            ++cur;
            //cout << "3: ";
            //display(a, begin, end);
        }
    }
    swap(a[ini], a[begin]);    //调整
    
    --ini;
    //cout << "ini: " << ini <<"  "<< "ter: " << ter << endl;
    //display(a, begin,end);
	return pair<int, int>(ini, ter);
        
}
void fuzzySortingOfInterval(Interval a[], int begin, int end)
{
	if (begin < end)
	{
		int ini, ter;
		partition(a, begin, end);
		ini = partition(a, begin, end).first;
		ter = partition(a, begin, end).second;
		fuzzySortingOfInterval(a, begin, ini);
		fuzzySortingOfInterval(a, ter, end);
	}
}
int main()
{    
    srand(time(NULL));
    const int size = 8;
    Interval a(28508,31359), b(4712,30466), c(23267,30245), d(7134,8098), e(25400,26351), f(8079,29052), g(31163,31738), h(6346,24352);
    Interval array[size] = {a, b, c, d, e, f ,g,h};
    /*Interval *array = new Interval[size];
    for (int i = 0; i < size; ++i)
    {
        array[i].leftbound = rand() % 100;
        array[i].rightbound = rand() % 100;
        while (array[i].rightbound < array[i].leftbound)
            array[i].rightbound = rand() % 100;
    }*/
   /* display(array, 0, size - 1);
    fuzzySortingOfInterval(array, 0, size - 1);
    display(array, 0, size - 1);
    system("pause");
}*/
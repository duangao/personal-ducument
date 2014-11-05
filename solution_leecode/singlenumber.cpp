/*
 * 异或在数字逻辑中有很多的应用，最简单的：
 * a^a=0,0^a=a,并且满足交换律和结合律，因此：
 * a^b^c^d^e的话，里面任意两个相同的数字得到0，因此最终的结果为0^singlenumber=singlenumber
 * 此题要求的是线性时间，所以依靠排序等是无法奏效的
 * */
class Solution {
public:
    int singleNumber(int A[], int n) {
        int result=A[0];
        for(int i=1;i<n;i++)
            result^=A[i];
        return result;
    }
};

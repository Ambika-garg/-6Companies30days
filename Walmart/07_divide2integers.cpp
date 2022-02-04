Problem Link: https://leetcode.com/problems/divide-two-integers/submissions/
-----------------------------------------------------------------------------


class Solution {
public:
    int divide(int dividend, int divisor) {
        if((dividend == INT_MAX && divisor==1) ||(dividend == INT_MIN && divisor==-1)){
            return INT_MAX;
        }
        if((dividend == INT_MIN && divisor == 1) || (dividend == INT_MAX && divisor==-1)){
            return INT_MIN;
        }
        if(dividend == 0) return 0;
        int sign=0 ;
        if(dividend<0 and divisor<0)
        {
            sign = 0;
        }
        else if(dividend<0 or divisor<0)
        {
            sign = -1;
        }
        long long int dend = abs(dividend);
        long long int sor = abs(divisor);
        int res = 0;
        while(dend - sor>=0)
        {
            int count = 0;
            while(dend-(sor<<count)>=0)
            {
                count++;
            }
            count--;
            res +=(1<<count);
            dend -= sor<<(count);
        }
        if(sign==-1)
        {
            return sign*res;
        }
        return res;
    }
    
};

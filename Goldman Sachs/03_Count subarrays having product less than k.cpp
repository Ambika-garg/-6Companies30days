Problem Link: https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#
----------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        if(k<=0)
        {
            return 0;
        }
        int res = 0;
        int n = a.size();
        int s = 0, e=0;
        int prod = 1;
        while(e<n)
        {
            prod = prod*a[e];
            while(s<=e and prod>=k)
            {
                prod /= a[s];
                s++;
            }
            if(prod==k)
            {
                return 0;
            }
            if(prod<k)
            {
                
                res = res + (e-s+1);
                e++;
            }
        }
        return res;
    }
};

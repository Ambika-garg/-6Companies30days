Problem Link: https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1#
--------------------------------------------------------------------------------------------------------------------
  
  
  class Solution{
    public:
    long long int dp[1001][1001];
    int p = 1e9+7;
    int findways(int n, int x, int index)
    {
        if(n==0)
        {
            return 1;
        }
        if(dp[n][index]!=-1)
        {
            return (dp[n][index])%p;
        }
        else
        {
            //include or exclude
            int y = pow(index,x);
            if(y<=n)
            {
                dp[n][index] = findways(n-y, x, index+1) + findways(n,x,index+1);
                return (dp[n][index])%p;
            }
            return 0;
        }
        return 0;
    }
    int numOfWays(int n, int x)
    {
        memset(dp, -1, sizeof(dp));
        int a = findways(n,x,1);
        return a;
    }
};

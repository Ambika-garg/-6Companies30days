Problem Link: https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/#
----------------------------------------------------------------------------------------------------------------

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        vector<long long> dp(m+1,0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=m;i++)
        {
            dp[i]=1+dp[i-2];
        }
        return dp[m];
    }
};

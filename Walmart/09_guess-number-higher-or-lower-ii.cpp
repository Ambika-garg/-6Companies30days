Problem Link: https://leetcode.com/problems/guess-number-higher-or-lower-ii
---------------------------------------------------------------------------------------------

class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n+1][n+1];
        
        for(int k=0;k<n;k++)
        {
            for(int i=1;i<=n-k;i++)
            {
                if(k==0)
                {
                    dp[i][i+k] = 0;
                }
                else if(k==1)
                {
                    dp[i][i+k] = i;
                }
                else
                {
                    int m = INT_MAX;
                    for(int j = i+1;j<=i+k-1;j++)
                    {
                        m =  min(m, max(dp[i][j-1], dp[j+1][i+k])+j);
                    }
                    dp[i][i+k] = m;
                }
                
            }
        }
        return dp[1][n];
    }
};

Problem Link: https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/#
------------------------------------------------------------------------------------------------------


class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2)
        {
            return n;
        }
        int dp[n][n] = {0};
        int maxlength = 2;
        for(int i=0;i<n-1;i++)
        {
            dp[i][n-1]=2;
        }
        for(int j=n-2;j>0;j--)
        {
            int i = j-1, k = j+1;
            while(k<n and i>=0)
            {
                if(A[i]+A[k]<2*A[j])
                {
                    k++;
                }
                else if(A[i]+A[k]>2*A[j])
                {
                    dp[i][j] = 2;
                    i--;
                }
                else
                {
                     dp[i][j] = dp[j][k]+1;
                     maxlength = max(maxlength, dp[i][j]);
                     i--;
                     k++;
                }
            } 
            while(i>=0)
            {
                dp[i][j] = 2;
                i--;
            }
        }
        return maxlength;
    }
};

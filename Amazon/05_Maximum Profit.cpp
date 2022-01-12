Problem Link: https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#
-------------------------------------------------------------------------------
  
  
  class Solution {
  public:
    int maxProfit(int K, int N, int arr[]) {
        vector<vector<int>> dp(K+1, vector<int>(N,0));
        
        for(int t = 1;t<=K;t++)
        {
            for(int d=1;d<N;d++)
            {
                dp[t][d] = dp[t][d-1];
                for(int i=0;i<d;i++)
                {
                    dp[t][d] = max(dp[t][d], dp[t-1][i]+arr[d]-arr[i]);
                }
            }
        }
        return dp[K][N-1];
    }
};

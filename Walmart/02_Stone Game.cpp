Problem Link: https://leetcode.com/problems/stone-game/
-----------------------------------------------------------


class Solution {
public:
    int maxpoints(vector<int> &piles, int s, int e,int dp[500][500])
    {
        if(s>=e)
        {
            return 0;
        }
        if(dp[s][e]!=0)
        {
            return dp[s][e];
        }
        else
        {
            int l = piles[s]+min(maxpoints(piles, s+2, e, dp),maxpoints(piles, s+1, e-1, dp));
            int r = piles[e]+min(maxpoints(piles, s+1, e-1, dp),maxpoints(piles, s, e-2, dp));
            dp[s][e] =  max(l,r);
            return dp[s][e];
        }
    }
    bool stoneGame(vector<int>& piles) {
        int s = 0;
        int e = piles.size()-1;
        int n = piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        
        int dp[500][500]={0};
        
        int a = maxpoints(piles, s, e,dp);
        
        if(sum-a<a)
        {
            return true;
        }
        return false;
    }
};

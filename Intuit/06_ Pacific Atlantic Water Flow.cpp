Problem Link: https://leetcode.com/problems/pacific-atlantic-water-flow/


class Solution {
public:
    bool inbounds(int r, int c, vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        if(r>=0 and r<m and c>=0 and c<n)
        {
            return true;
        }
        return false;
    }
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>>& heights, int prevheight)
    {
        if(inbounds(r,c,heights) and vis[r][c]==0)
        {
            if(heights[r][c]>=prevheight)
            {
                vis[r][c]=1;
                dfs(r,c+1,vis,heights, heights[r][c]);
                dfs(r,c-1,vis,heights, heights[r][c]);
                dfs(r+1,c,vis,heights, heights[r][c]);
                dfs(r-1,c,vis,heights, heights[r][c]);
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size(); 
        vector<vector<int>> pac(m,vector<int>(n,0));
        vector<vector<int>> atl(m,vector<int>(n,0));
        
        //calling for top and bottom row
        for(int c=0;c<n;c++)
        {
            dfs(0, c, pac, heights, heights[0][c]);
        }
        for(int c=0;c<n;c++)
        {
            dfs(m-1, c, atl, heights, heights[m-1][c]);
        }
        for(int r=0;r<m;r++)
        {
            dfs(r, 0, pac, heights, heights[r][0]);
        }
        for(int r=0;r<m;r++)
        {
            dfs(r, n-1, atl, heights, heights[r][n-1]);
        }
        
        
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(atl[i][j]==1 and pac[i][j]==1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};

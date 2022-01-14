Problem Link: https://leetcode.com/problems/rotting-oranges/
-------------------------------------------------------------------


class Solution {
public:
    
    int caltime(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int t;
        while(!q.empty())
        {
            pair<pair<int, int>, int> r = q.front();
            int i= r.first.first;
            int j = r.first.second;
            t = r.second;
            q.pop();
            if((0<=i and i<n) and (0<=j and j<m))
            {
                if(i+1>=0 and i+1<n and grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    q.push({{i+1,j}, t+1});
                }
                if(i-1>=0 and grid[i-1][j]==1)
                {
                    grid[i-1][j]=2;
                    q.push({{i-1,j}, t+1});
                }
                if(j+1>=0 and j+1<m and  grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    q.push({{i,j+1}, t+1});
                }
                if(j-1>=0 and grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    q.push({{i,j-1}, t+1});
                }
            }
            
            
        }
        return t;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int y;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        if((n<=0 or m<=0))
        {
            return 0;
        }
        else if(n==1 and m==1 and (grid[0][0]==2 or grid[0][0]==0))
        {
            return 0;
        }
        else
        {
            int time = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<grid[i].size();j++)
                {
                    if(grid[i][j]==2)
                    {
                        q.push({{i,j}, 0});
                    }
                    
                }
            }
            
            if(!q.empty())
            {
                y = caltime(q,grid);
            }
            
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                       return -1;
                    }
                    
                }
            }
            int count = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<grid[i].size();j++)
                {
                    if(grid[i][j]==0)
                    {
                       count++;
                    }
                    
                }
            }
            if(count ==n*m)
            {
                return 0;
            }
            return y;
            
        }
        
        
    }
};

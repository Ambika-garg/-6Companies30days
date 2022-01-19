Problem Link: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/#
-------------------------------------------------------------------------------------------------------------


class Solution
{
    public:
    
    //Function to find unit area of the largest region of 1s.
    
    int countarea(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
        {
            return 0;
        }
        
        vector<int> x = { -1, -1, -1, 1, 1, 1, 0, 0 };
        vector<int> y = { 1,0,-1,1,0,-1,1,-1};
        grid[i][j]=0;//mark visited
        
        //traversing through all the directions
        int area=  0;
        for(int k=0;k<8;k++)
        {
            area = area + countarea(grid, i+x[k], j+y[k]);
        }
        
        return area+1;
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        
        int maxarea = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    maxarea=max(maxarea, countarea(grid, i, j));
                }
            }
        }
        return maxarea;
    }
};

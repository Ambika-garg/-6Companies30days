Problem Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/#
-------------------------------------------------------------------------------------------------------------
  
  
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> vec;
        int total = r*c;
        int count =0;
        int srow= 0, ecol = c-1, erow=r-1, scol=0; 
        while(vec.size()<total)
        {
            if(vec.size()<total)
            {
                for(int i=scol;i<=ecol;i++)
                {
                    vec.push_back(matrix[srow][i]);
                }
                srow++;
            }
            
            if(vec.size()<total)
            {
                for(int i=srow;i<=erow;i++)
                {
                    vec.push_back(matrix[i][ecol]);
                }
                ecol--;
            
            }
            
            if(vec.size()<total)
            {
                for(int i=ecol;i>=scol;i--)
                {
                    vec.push_back(matrix[erow][i]);
                }
                erow--;
            }
            
            if(vec.size()<total)
            {
                for(int i=erow;i>=srow;i--)
                {
                    vec.push_back(matrix[i][scol]);
                }
                scol++;
            }
            
        }
        return vec;
        
    }
};

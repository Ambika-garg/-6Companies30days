Problem Link: https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/#
------------------------------------------------------------------------------------
  
  
  class Solution{
public:

    bool valid(vector<vector<int>> &mat, int i, int j)
    {
        int key = mat[i][j];
        if(key==0)
        {
            return true;
        }
        for(int k=0;k<9;k++)
        {
            if(key==mat[i][k] and k!=j)
            {
                return false;
            }
        }
        
        for(int k=0;k<9;k++)
        {
            if(key==mat[k][j] and k!=i)
            {
                return false;
            }
        }
        
        int r = i - i%3;//row starting
        int c = j - j%3;//col starting
        
        for(int k=r; k<r+3; k++)
        {
            for(int l=c; l<c+3; l++)
            {
                if(key==mat[k][l] and k!=i and l!=j)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    int isValid(vector<vector<int>> mat){
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(!valid(mat,i,j))
                {
                    // cout<<"i: "<<i<<"j: "<<j<<"no: "<<mat[i][j];
                    return false;
                }
            }
        }
        return true;
    }
};

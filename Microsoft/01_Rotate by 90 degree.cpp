Problem Link: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/#
-----------------------------------------------------------------------------------------


void rotate(vector<vector<int> >& matrix)
{
    // transpose matrix
    int n = matrix.size();
    for(int i=0;i<n;i++)
    {
        for(int j= i+1;j<n;j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // make 1st row last row
    int k = n-1;
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(matrix[i][j], matrix[k][j]);
        }
        k--;
    }
}

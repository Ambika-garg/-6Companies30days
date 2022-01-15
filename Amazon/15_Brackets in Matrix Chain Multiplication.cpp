Problem Link: https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/#
------------------------------------------------------------------------------------------------------------

class Solution{
public:

    void printbrackets(int i, int j, int brackets[101][101],string& s, char& name)
    {
        //base case: if printbrackets is called for 1,1(example)
        if(i==j)
        {
            s.push_back(name++);
            return;
        }
        else
        {
            s.push_back('(');
            printbrackets(i, brackets[i][j],brackets, s, name);
            printbrackets(brackets[i][j]+1, j, brackets, s, name);
            s.push_back(')');
        }
    }
    string matrixChainOrder(int p[], int n){
        
        int dp[101][101] = {0};
        int brackets[101][101] = {0};
        
        for(int i=1;i<n;i++)
        {
            dp[i][i]=0;
        }
        
        for(int L=2;L<n;L++)
        {
            for(int i=1;i<n-L+1;i++)
            {
                int j = i+L-1;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int q = dp[i][k]+dp[k+1][j]+(p[i-1]*p[k]*p[j]);
                    // cout<<q<<" ";
                    if(q<dp[i][j])
                    {
                        
                        dp[i][j]=q;
                        brackets[i][j]= k;
                    }
                }
            }
        }
        
        
        
        char name='A';
        string ans;
        
        printbrackets(1, n-1, brackets, ans, name);
        return ans;
        
        
    }
};

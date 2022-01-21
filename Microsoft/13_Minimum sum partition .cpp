Problem Link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#
--------------------------------------------------------------------------------------------
  
  
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    if(n==1)
	    {
	        return arr[0];
	    }
	    if(n==2)
	    {
	        return abs(arr[1]-arr[0]);
	    }
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum = sum+arr[i];
	    }
	    
	    //DP gives us if sum j is possible or not. 
	    int rows = n+1;
	    int cols = sum+1;
	    int dp[rows][cols];
	    dp[0][0] = 1;
	    
	    for(int i=0;i<rows;i++)
	    {
	        for(int j=0;j<cols;j++)
	        {
	            if(i==0 and j!=0)
	            {
	                dp[i][j] = 0;
	            }
	            if(i!=0 and j==0)
	            {
	                dp[i][j]=1;
	            }
	        }
	    }
	    for(int i=1;i<rows;i++)
	    {
	        for(int j=1;j<cols;j++)
	        {
	            if(arr[i-1]>j)
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	            else
	            {
	                //either include or exclude 
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }
	            
	        }
	    }
	    int diff=INT_MAX;
	    for(int i=0;i<=(sum/2);i++)
	    {
	        int s1 = i;
	        int s2 = sum-i;
	        if(dp[n][i]==1 and diff>abs(s1-s2))
	        {
	            diff = abs(s2-s1);
	        }
	    }
	    return diff;
	} 
};

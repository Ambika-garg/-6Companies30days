Problem : https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1#
------------------------------------------------------------------------------------


class Solution {
	public:

	int CountWays(string str){
	    //following tabular approach
	    if(str[0]=='0')
	    {
	        return 0;
	    }
	    int n = str.size();
	    vector<int> dp(n,0);
	    
	    dp[0] = 1;
	    string s = str;
	    for(int i=1;i<n;i++)
	    {
	        if(s[i-1]=='0' && s[i]=='0')
	        {
	            dp[i] = 0;
	        }
	        else if(s[i-1]=='0' or s[i]=='0')
	        {
	            if((s[i-1]=='1' or s[i-1]=='2') and s[i]=='0')
	            {
	                if(i==1)
    	            {
    	                dp[i] = 1;
    	            }
    	            else
    	            {
    	                dp[i] = dp[i-2];
    	            }
	            }
	            else if(s[i-1]=='0')
	            {
	                dp[i]=dp[i-1];
	            }
	            else
	            {
	                dp[i]=0;
	            }
	            
	        }
	        else
	        {
	            string temp = s.substr(i-1,2);
	            if(9<stoi(temp) and stoi(temp)<=26)
	            {
	                
	                if(i==1)
	                {
	                    dp[i]=(dp[i-1]+1)%1000000007;
	                }
	                else
	                {
	                    
	                    dp[i]=(dp[i-1]+dp[i-2])%1000000007;
	                }
	                
	            }
	            else
	            {
	                dp[i]=dp[i-1];
	            }
	        }
	    }
	    return dp[n-1];
	}
};

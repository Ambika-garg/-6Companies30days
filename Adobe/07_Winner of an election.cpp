Problem Link: https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/#
---------------------------------------------------------------------------------------------------------------------------------------------
  
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        vector<string> vec;
        
        int m = INT_MIN;
        string s;
        for(auto i:mp)
        {
            int t = max(m, i.second);
            if(t==m)
            {
                if(s>i.first)
                {
                    s = i.first;
                    
                }
                m = max(m,i.second);
            }
            else if(t>m)
            {
                s = i.first;
                m = max(m,i.second);
            }
            
        }
        
        return {s, to_string(m)};
    }
};

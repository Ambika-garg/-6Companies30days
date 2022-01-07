Problem Link: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1
------------------------------------------------------------------------------------------
  
class Solution{   
public:
    string reverse(string ans, int s, int e, int n)
    {
        while(s<e)
        {
            swap(ans[s], ans[e]);
            s++;
            e--;
        }
        return ans;
    }
    string printMinNumberForPattern(string S){
        string ans;
        int lastdigit = 1;
        for(int i=0;i<=S.size();i++)
        {
            ans = ans+to_string(lastdigit);
            lastdigit++;
        }
        
        int i=0;
        while(i<S.size())
        {
            if(S[i]=='D')
            {
                int s = i;
                while(S[i]=='D')
                {
                    i++;
                }
                int e = i;
                ans = reverse(ans, s, e, S.size()+1);
                // cout<<ans<<" ";
            }
            i++;
        }
        return ans;
    }
};

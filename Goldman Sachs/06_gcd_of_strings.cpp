Problem Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/
------------------------------------------------------------------------------------------
  
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        if(str1.size()>str2.size())
        {
            swap(str1, str2);
        }
        for(int k=str1.size();k>=1;k--)
        {
            string s = str1.substr(0, k);
            
            int flag = 1;
            for(int i=0;i<str2.size();i+=k)
            {
                if(str2.substr(i, k)!=s)
                {
                    flag = 0;
                    continue;
                }
            }
            
            if(flag==0){continue;}
            for(int j=0;j<str1.size();j+=k)
            {
                if(str1.substr(j, k)!=s)
                {
                    flag = 0;
                    continue;
                }
            }
            
            if(flag==0){continue;}
            
            if(flag==1)
            {
                return s;
            }
            
        }
        return "";
        
    }
};

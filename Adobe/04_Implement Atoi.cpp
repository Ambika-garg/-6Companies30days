Problem Link: https://practice.geeksforgeeks.org/problems/implement-atoi/1/#
-----------------------------------------------------------------------------
  
  
  
  
class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        unsigned int ans=0;
        int sign = 1;
        for(auto i: str)
        {
            if(i=='-')
            {
                sign = -1;
            }
            else if(i>='a' and i<='z' or i>='A' and i<='Z')
            {
                return -1;
            }
            else
            {
                int x = i-'0';
                ans = ans*10+x;
            }
            
        }
        return ans*sign;
    }
};

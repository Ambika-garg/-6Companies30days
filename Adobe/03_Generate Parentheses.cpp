Problem Link: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/#
---------------------------------------------------------------------------------------------------
  
  
  class Solution
{
    public:
    void balanced(vector<string> &vec, int open, int close, string str)
    {
        //when all brackets are consumed
        if(open==0 and close==0)
        {
            vec.push_back(str);
            return;
        }
        else if(open==0)
        {
            //only closed brackets are left
            balanced(vec, open, close-1, str+')');
        }
        else if(open==close)
        {
            //we will start with open bracket
            balanced(vec, open-1, close, str+'(');
        }
        else
        {
            balanced(vec, open-1, close, str+'(');
            balanced(vec, open , close-1, str+')');
            return;
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> vec;
        int open =n;
        int close = n;
        balanced(vec, open, close, "");
        return vec;
    }
};

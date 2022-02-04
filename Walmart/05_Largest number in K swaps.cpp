Problem Link: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1/
------------------------------------------------------------------------------------------------------


class Solution
{
    public:
    // Function to find the largest number after k swaps.
    vector<int> maxno(string &str, int idx)
    {
        vector<int> vec;
        int midx;
        int m = INT_MIN;
        for(int i=idx+1;i<str.length();i++)
        {
            if(str[idx]<str[i] and m<=str[i])
            {
                m = str[i];
                midx=i;
            }
        }
        for(int i= idx+1;i<=midx;i++)
        {
            if(str[i]==m)
            {
                vec.push_back(i);
            }
        }
        return vec;
    }
    void findMaximum(string &str, int idx, int k, string &mstr)
    {
        if(k<=0)
        {
            return;
        }
        else if(idx>=str.length())
        {
            return;
        }
        else
        {
            vector<int> idxvec = maxno(str, idx);
            if(!idxvec.empty())
            {
                k--;
                for(int j =0; j<idxvec.size(); j++)
                {
                    swap(str[idxvec[j]], str[idx]);
                    mstr = max(str,mstr);
                    findMaximum(str, idx+1, k, mstr);
                    swap(str[idxvec[j]], str[idx]);
                }
            }
            else
            {
                
                findMaximum(str, idx+1, k, mstr);
            }
            
        }
    }
    string findMaximumNum(string str, int k)
    {
      int idx = 0;
      string mstr = str;
      findMaximum(str, idx, k, mstr);
      return mstr;
    }
};

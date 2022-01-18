Problem Link: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/#
----------------------------------------------------------------------------------------------------------
  
  
  class Solution
{
    public:
    
    //Function to find list of all words possible by pressing given numbers.
    unordered_map<int, string> dict = {{2, "abc"}, {3, "def"}, {4, "ghi"},{5, "jkl"}, {6, "mno"}, {7, "pqrs"},{ 8, "tuv"}, {9, "wxyz"}};
    void findwords(int a[], int N, vector<string> &vec, int index, string str)
    {
        if(index>=N)
        {
            vec.push_back(str);
            return;
        }
        else
        {
            string temp = dict[a[index]];
            for(int i=0;i<temp.size();i++)
            {
                findwords(a,N,vec, index+1, str+temp[i]);
            }
            return;
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> vec;
        if(N==0)
        {
            return vec;
        }
        string str = "";
        findwords(a, N, vec, 0, str);
        
        return vec;
    }
};

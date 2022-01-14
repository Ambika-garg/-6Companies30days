Problem Link: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/#
--------------------------------------------------------------------------------------------------------


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s = "";
        while(n !=0)
        {
            n--;
            
            int r = n%26;
            s = string(1, r+'A')+s;
            n = n/26;
        }
        
        return s;
    }
};

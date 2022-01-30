Problem Link: https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/#
-----------------------------------------------------------------------------------------------------------------------------------
  
  // { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextpermute(string temp)
    {
        int n = temp.length();
        int idx=-1;
        for(int i = n-1;i>0;i--)
        {
            if(temp[i]-'0'>temp[i-1]-'0')
            {
                idx = i-1;
                break;
            }
        }
        
        
        if(idx==-1)
        {
            return temp;
        }
        else
        {
            int nearest=INT_MAX;
            int y;
            for(int i=idx+1;i<n;i++)
            {
                int a = temp[i]-'0';
                
                if(a>temp[idx]-'0')
                {
                    nearest = min(nearest, a);;
                    y = i;
                }
            }
            if(nearest!=INT_MAX)
            {
                swap(temp[y], temp[idx]);
            }
            int len = n-idx;
            int j = n;
            for(int i = idx+1; i<=idx+(len)/2;i++)
            {
                if(j>i)
                {
                    swap(temp[i], temp[j-1]);
                    j--;
                }
                
            }
        }
        return temp;
    }
    string nextPalin(string N) { 
        //complete the function here
        int x = N.length();
        if(x%2==0)
        {
            //palindrome is of even length
            string temp = N.substr(0,x/2);
            string s = nextpermute(temp);
            if(s==temp)
            {
                return "-1";
            }
            string t = string(s.rbegin(), s.rend());
            s = s+t;
            return s;
        }
        else
        {
            string temp = N.substr(0,x/2);
            string s = nextpermute(temp);
            if(s==temp)
            {
                return "-1";
            }
            string t = string(s.rbegin(), s.rend());
            s = s+N[(x/2)] + t;
            return s;
        }
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends

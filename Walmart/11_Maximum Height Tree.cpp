Problem Link: https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart#
---------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int height(int N){
        if(N==0 or N==1)
        {
            return 1;
        }
        int sum=0;
        for(int i=1;i<=N;i++)
        {
            sum=sum+i;
            if(sum==N)
            {
                
                return i;
            }
            else if(sum>N)
            {
                
                return i-1;
            }
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}  // } Driver Code Ends

Problem Link: https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart
----------------------------------------------------------------------------------------------------------------------------------------------------------------


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

 // } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    long long findpow(int N, int R, int P)
    {
        if(R==0)
        {
            return 1;
        }
        else
        {
            if(R&1)
            {
                return ((N%P)*findpow(N,R-1, P))%P;
            }
            else
            {
                long long y = findpow(N,R/2,P);
                return (y*y)%P;
            }
        }
    }
    long long power(int N,int R)
    {
       int P = 1e9+7;
       long long a = findpow(N, R, P);
       return a;
        
    }

};

// { Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}  // } Driver Code Ends

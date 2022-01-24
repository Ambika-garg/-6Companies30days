Problem Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
---------------------------------------------------------------------------------------------------
  
  
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int i=0,j=0;
        int sum=0;
        while(j<n and sum<s)
        {
            sum = sum+arr[j];
            if(sum>s)
            {
                while(i<n and sum>s)
                {
                    sum = sum-arr[i];
                    i++;
                }
            }
            if(sum==s)
            {
                return {i+1,j+1};
            }
            j++;
        }
        return {-1};
    }
};

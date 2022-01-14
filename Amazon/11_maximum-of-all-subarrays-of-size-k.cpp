Problem Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#
----------------------------------------------------------------------------------------------------




class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> maxq;
        int j=0,i=0;
        while(j<n)
        {
            if(maxq.empty())
            {
                maxq.push_back(arr[j]);
            }
            else
            {
                while(!maxq.empty() and maxq.back()<arr[j])
                {
                    maxq.pop_back();
                }
                maxq.push_back(arr[j]);
            }
            if(j-i+1==k)
            {
                ans.push_back(maxq.front());
                if(arr[i]==maxq.front())
                {
                    maxq.pop_front();
                }
                i++;
                j++;
            }
            else
            {
                j++;
            }
            
        }
        return ans;
    }
};

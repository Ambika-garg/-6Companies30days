Problem Link: https://leetcode.com/problems/longest-mountain-in-array/
----------------------------------------------------------------------



class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<=2)
        {
            return 0;
        }
        bool peak = false;
        bool valley = false;
        int start;
        int ans = 0;
        int n = arr.size();
        int i=0;
        while(i<n-1)
        {
            if(arr[i]<arr[i+1])
            {
                start = i;
                while((i<n-1) and arr[i]<arr[i+1])
                {
                    peak = true;
                    i++;
                }
                while((i<n-1) and arr[i]>arr[i+1])
                {
                    valley = true;
                    i++;
                }
                if(peak == true and valley == true)
                {
                    ans = max(ans, i-start+1);
                    
                }
                peak = false;
                valley = false;
            }
            else
            {
                i++;
            }
        }
            
        return ans;
    }
    
};

Problem Link: https://leetcode.com/problems/split-array-largest-sum/
-------------------------------------------------------------------------------------


class Solution {
public:
    bool can_split(vector<int>& nums, int mid, int m)
    {
        int stud = 1;
        int sum = 0;
        for(int x:nums)
        {
            sum = sum+x;
            if(sum>mid)
            {
                sum = x;
                stud++;
            }
            
        }
        
        if(sum<=mid and stud<=m)
        {
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int high = accumulate(nums.begin(), nums.end(), 0);
        int low = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(low<=high)
        {
            cout<<"low: "<<low<<"high: "<<high<<endl;
            int mid = (low+high)/2;
            if(can_split(nums, mid, m))
            {
                ans = mid;
                high = mid-1;
                
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};

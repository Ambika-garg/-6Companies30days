Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/
-----------------------------------------------------------------------

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0,j=0;
        int ans = INT_MAX;
        int pre_sum = 0;
        while(i<=j and j<nums.size())
        {
            if(pre_sum<target)
            {
                pre_sum = pre_sum+nums[j];
                
            }
            
            while(pre_sum>=target and i<nums.size())
            {
                ans = min(ans, j-i+1);
                pre_sum = pre_sum - nums[i];
                i++;
            }
            j++;
            
        }
        return ans==INT_MAX?0:ans;
    }
};

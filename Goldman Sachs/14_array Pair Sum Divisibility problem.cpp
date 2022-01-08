Problem Link: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#
----------------------------------------------------------------------------------------------------


class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int, int> hashmap;
        
        for(int i=0;i<nums.size();i++)
        {
            int a = nums[i]%k;
            hashmap[a]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            int rem = nums[i]%k;
            
            if(rem==0)
            {
                if(hashmap[rem]%2!=0)
                {
                    return false;
                }
            }
            else if(2*rem==k)
            {
                if(hashmap[rem]%2!=0)
                {
                    return false;
                }
            }
            else
            {
                if(hashmap[rem]!=hashmap[k-rem])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};

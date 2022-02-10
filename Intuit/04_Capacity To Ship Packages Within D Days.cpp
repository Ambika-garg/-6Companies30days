Problem Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
--------------------------------------------------------------------------------------


class Solution {
public:
    int find_capacity(vector<int> &weights, int high, int low, int target)
    {
        
        int mid;
        int temp = INT_MAX;
        while(low<=high)
        {
            mid = (low+high)/2;
            int ans = 1;
            int sum = 0;
            for(int i=0;i<weights.size();i++)
            {
                sum = sum+weights[i];
                if(sum>mid)
                {
                    sum = weights[i];
                    ans++;
                }
            }
            if(ans<=target)
            {
                high = mid-1;
                temp = min(temp, mid);
            }
            else
            {
                low = mid+1;
            }
        }
        return temp;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());
        
        int cap = find_capacity(weights, high, low, days);
        return cap;
    }
};

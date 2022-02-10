Problem Link: https://leetcode.com/problems/find-in-mountain-array/submissions/
----------------------------------------------------------------------------------------

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findpeak(MountainArray &mountainArr,int low, int high)
    {
        if(low>high)
        {
            return -1;
        }
        else
        {
            int mid = (low+high)/2;
            if(mountainArr.get(mid+1)>mountainArr.get(mid))
            {
                int a = findpeak(mountainArr, mid+1, high);
                return a;
            }
            else if(mountainArr.get(mid-1)>mountainArr.get(mid))
            {
                int b = findpeak(mountainArr, low, mid-1);
                return b;
            }
            else
            {
                return mid;
            }
        }   
    }
    int findtarget(int low, int high, int target, MountainArray &mountainArr)
    {
        if(low>high)
        {
            return -1;
        }
        else
        {
            int mid = (low+high)/2;
            if(mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if(mountainArr.get(mid)>target)
            {
                int a = findtarget(low, mid-1, target, mountainArr);
                return a;
            }
            else
            {
                int b = findtarget(mid+1, high, target, mountainArr);
                return b;
            }
        }
    }
    int findtargetR(int low, int high, int target, MountainArray &mountainArr)
    {
        if(low>high)
        {
            return -1;
        }
        else
        {
            int mid = (low+high)/2;
            if(mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if(mountainArr.get(mid)>target)
            {
                int a = findtargetR(mid+1, high, target, mountainArr);
                return a;
            }
            else
            {
                int b = findtargetR(low, mid-1, target, mountainArr);
                return b;
            }
        }
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak_index = findpeak(mountainArr, 0, n-1);
        int a = findtarget(0, peak_index, target, mountainArr);
        int b = findtargetR(peak_index, n-1, target, mountainArr);
        if(a==-1)
        {
            return b;
        }
        else if(b==-1)
        {
            return a;
        }
        return min(a,b);
    }
};

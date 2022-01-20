Problem Link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
----------------------------------------------------------------------------------------------
  
  
  
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        set<vector<int>> vec;
        vector<vector<int>> ans;
        if(arr.size()<=3)
        {
            return ans;
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int x = 0;
        int y,a,b;
        y = x+1;
        a = y+1;
        b = n-1;
        while(x<n)
        {
            y = x+1;
            while(y<n-2)
            {
                a = y+1;
                b = n-1;
                while(a<b and a<n)
                {
                    int sum = arr[x]+arr[y]+arr[a]+arr[b];
                    if(sum<k)
                    {
                        a++;;
                    }
                    else if(sum>k)
                    {
                        b--;
                    }
                    else if(sum==k)
                    {
                        vec.insert({arr[x], arr[y], arr[a], arr[b]});
                        a++;
                        b--;
                    }
                }
                y++;
            }
            x++;
        }
        
        
        for(auto i: vec)
        {
            ans.push_back(i);
        }
        return ans;
    }
};

Problem Link: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/#
------------------------------------------------------------------------------------------------------
  
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        int i=0,j=0;
        deque<int> q;
        vector<int> vec;
        while(j<n)
        {
            if(q.empty())
            {
                q.push_back(arr[j]);
            }
            else 
            {
                int maxele = q.front();
                if(arr[j]>maxele)
                {
                    while(arr[j]>maxele)
                    {
                        q.pop_front();
                        if(q.empty())
                        {
                            break;
                        }
                        maxele = q.front();
                    }
                    q.push_back(arr[j]);
                }
                else if(arr[j]<=maxele)
                {
                    int maxele = q.back();
                    if(arr[j]>maxele)
                    {
                        while(arr[j]>maxele)
                        {
                            q.pop_back();
                            if(q.empty())
                            {
                                break;
                            }
                            maxele = q.back();
                        }
                        q.push_back(arr[j]);
                    }
                    else
                    {
                        q.push_back(arr[j]);
                    }
                    
                }
            }
            if(j-i+1==k)
            {
                vec.push_back(q.front());
                if(q.front()==arr[i])
                {
                    q.pop_front();
                }
                i++;j++;
            }
            else
            {
                j++;
            }
        }
        return vec;
    }
};

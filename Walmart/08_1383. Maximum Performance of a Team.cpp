Problem Link: https://leetcode.com/problems/maximum-performance-of-a-team/
----------------------------------------------------------------------------


class Solution {
public:
    typedef pair<int, int> pi;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
    {
        priority_queue<pair<int,int>> minheap;
        priority_queue<pi, vector<pi>, greater<pi>> mh;
        for(int i=0;i<n;i++)
        {
            minheap.push({efficiency[i], speed[i]});
        }
        long long int maxp = INT_MIN;
        long long int eff = INT_MIN;
        long long int performance = INT_MIN;
        
        pair<int, int> p = minheap.top();
        minheap.pop();
        
        maxp = p.second;
        eff = p.first;
        
        mh.push({maxp, eff});
        performance = maxp*eff;
        
        int i=1;
        while(!minheap.empty())
        {
            pair<int, int> p = minheap.top();
            eff = p.first;
            if(i<k)
            {
                mh.push({p.second, p.first});
                maxp = maxp+p.second;
                i++;
                
            }
            else
            {
                pair<int, int> o = mh.top();
                mh.pop();
                mh.push({p.second, p.first});
                maxp = maxp - o.first + p.second;
            }
            if(maxp*eff>performance)
            {
                performance = maxp*eff;
            }
            
            minheap.pop();
        }
        return (performance)%(1000000007);
    }
};

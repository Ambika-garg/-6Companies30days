problem Link: https://leetcode.com/problems/number-of-boomerangs/


class Solution {
public:
    bool findDist(vector<vector<int>> &vec)
    {
        int x1 = vec[0][0];
        int y1 = vec[0][1];
        
        int x2 = vec[1][0];int y2 = vec[1][1];
        int dist1 = pow(x2 - x1, 2) +pow(y2 - y1, 2);
        
        int x3 = vec[2][0];int y3 = vec[2][1];
        int dist2 = pow(x3 - x1, 2) +pow(y3 - y1, 2);
        
        
        if(dist1==dist2)
        {
            return 1;
        }
        return 0;
    }
    int ans = 0;
    void findboom(vector<vector<int>>& points, vector<vector<int>> &vec,vector<int> &vis)
    {
        if(vec.size()==3)
        {
            if(findDist(vec))
            {
                ans++;
            }
            return;
        }
        else
        {
            for(int i=0;i<points.size();i++)
            {
                if(vis[i]==0)
                {
                    vis[i]=1;
                    vec.push_back(points[i]);
                    findboom(points, vec, vis);
                    vis[i]=0;
                    vec.pop_back();
                }
                
            }
            return;
        }
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        vector<vector<int>> vec;
        int n =points.size();
        vector<int> vis(n,0);
        findboom(points, vec, vis);
        return ans;
    }
};

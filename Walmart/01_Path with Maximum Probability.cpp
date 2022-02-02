Problem link: https://leetcode.com/problems/path-with-maximum-probability/
---------------------------------------------------------------------------------------
  
  
  
  class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> graph(n);
        for(int i=0; i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pair<int,double>> pq;
        vector<double> dist(n,0.0);
        pq.push({start, 1.0});
        dist[start] = 1.0;
        
        
        while(!pq.empty())
        {
            int u = pq.top().first;
            pq.pop();
            cout<<u<<": ";
            for(auto &v: graph[u])
            {
                if(v.second*dist[u] > dist[v.first])
                {
                    dist[v.first] = v.second*dist[u];
                    pq.push({v.first, dist[v.first]});
                }
            }
        }
        
        return dist[end];
        
        
    }
};

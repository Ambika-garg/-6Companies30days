Problem Link: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1#
--------------------------------------------------------------------------------------
  
  
  class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    
    void dfs(int edge, vector<int> adj[], int c, int d, vector<int> &vis)
    {
        vis[edge] = 1;
        for(auto x: adj[edge])
        {
            if(edge==c and x==d){
                continue;
            }
            else
            {
                if(!vis[x])
                {
                    dfs(x,adj,c,d,vis);
                }
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> vis(V, 0);
        
        dfs(c, adj, c, d, vis);
        return (!vis[d]);
    }
};

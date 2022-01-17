Problem Link: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
------------------------------------------------------------------------------------


class Solution {
public:

    void addEdge(vector<int> Adj[], int u, int v)
    {
        Adj[u].push_back(v);
        return;
    }
    bool iscyclic_util(int edge, bool vis[], vector<int> Adj[], int N, bool parent[])
    {
        parent[edge] = true;
        for(auto i: Adj[edge])
        {
            if(vis[i])
            {
                return true;
            }
            else
            {
                if(!parent[i])
                {
                    vis[i]=true;
                    if(iscyclic_util(i, vis, Adj, N, parent))
                    {
                        return true;
                    }
                    vis[i] = false;
                }
                
            }
        }
        return false;
    }
    bool iscyclic(int N, vector<int> Adj[])
    {
        bool vis[N] = {false};
        bool parent[N] = {false};
        for(int i=0;i<N;i++)
        {
            if(!vis[i] and !parent[i])
            {
                vis[i] = true;
                parent[i] = true;
                if(iscyclic_util(i, vis, Adj, N, parent))
                {
                    return true;
                }
                vis[i] = false;
            }
        }
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	   
	    vector<int> Adj[N];
	    
	    for(auto i: prerequisites)
	    {
	        addEdge(Adj, i.first, i.second);
	    }
	    
	    if(iscyclic(N, Adj))
	    {
	        return false;
	    }
	    return true;
	}
};

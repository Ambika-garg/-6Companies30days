Problem Link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1/#
---------------------------------------------------------------------------------



class Solution{
    public:
    void TS_Util(vector<int> graph[], stack<int> &st, int edge, vector<bool> &vis)
    {
        vis[edge]=true;
        for(auto i: graph[edge])
        {
            if(!vis[i])
            {
                TS_Util(graph, st, i, vis);
            }
        }
        st.push(edge);
    }
    string topological_sort(vector<int> graph[], int V)
    {
        vector<bool> vis(V,false);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                TS_Util(graph, st, i, vis);
            }
        }
        
        string ans;
        while(!st.empty())
        {
            char a = (char)('a'+st.top());
            ans.push_back(a);
            st.pop();
        }
        return ans;
    }
    void addEdge(vector<int> graph[], int u, int v)
    {
        graph[u].push_back(v);
        return;
    }
    string findOrder(string dict[], int N, int K) {
        
        vector<int> graph[K];
        
        //Make Graph
        for(int i=0;i<N-1;i++)
        {
            string w1 = dict[i];
            string w2 = dict[i+1];
            for(int j=0;j<min(w1.length(), w2.length());j++)
            {
                if(w1[j]!=w2[j])
                {
                    addEdge(graph, w1[j]-'a', w2[j]-'a');
                    break;
                }
            }
        }
        
        //topological sort
        
        string ans = topological_sort(graph, K);
        return ans;
    }
};

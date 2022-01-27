Problem Link: https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/#
----------------------------------------------------------------------------------------------------------------------
  
  
class Solution{
    public:
    typedef pair<int, pair<int, int>> pai;
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        int range = INT_MAX;
        int mn=INT_MAX; //index of min ele
        int mx = INT_MIN;//index of max ele
        pair<int, int> ans;
        pair<int,int> mini_index;
        priority_queue<pai, vector<pai>, greater<pai>> q;
        
        for(int i=0;i<k;i++)
        {
          q.push(make_pair(KSortedArray[i][0], make_pair(i,0)));
          mx = max(mx, KSortedArray[i][0]);
        }
        
        int maxele,minele;
        while(1)
        {
            mn = q.top().first;
            mini_index = q.top().second;
            
            q.pop();
            if(mx-mn<range)
            {
                maxele = mx;
                minele = mn;
                range = mx-mn;
                ans = make_pair(mn, mx);
            }
            int r = mini_index.first;
            int c = mini_index.second+1;
            if(c==n)
            {
                break;
            }
            if(KSortedArray[r][c]>mx)
            {
                mx = KSortedArray[r][c];
            }
            q.push(make_pair(KSortedArray[r][c], make_pair(r,c)));
        }
        return ans;
    }
};

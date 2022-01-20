Problem Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
----------------------------------------------------------------------------------------------



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int, int>> st;
       
       vector<int> ans;
       
       for(int i=0;i<n;i++)
       {
           if(st.empty())
           {
               st.push({price[i], 1});
               ans.push_back(1);
           }
           else
           {
               if(st.top().first>price[i])
               {
                   st.push({price[i], 1});
                   ans.push_back(1);
               }
               else
               {
                   int j=0;
                   while(!st.empty() and st.top().first<=price[i])
                   {
                       j = j+st.top().second;
                       st.pop();
                   }
                   st.push({price[i], j+1});
                   ans.push_back(j+1);
               }
           }
       }
       return ans;
    }
};

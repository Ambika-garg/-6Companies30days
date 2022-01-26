Problem Link: https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/#
---------------------------------------------------------------------------------------------



class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        deque<int> q;
        int i=0;
        vector<int> vec;
        while(i<n)
        {
            if(q.empty())
            {
                q.push_back(a[i]);
            }
            else
            {
                int t = q.back();
                if(a[i]<t)
                {
                    q.push_back(a[i]);
                }
                else if(a[i]>t)
                {
                    while(!q.empty() and a[i]>t)
                    {
                        q.pop_back();
                        if(!q.empty())
                        {
                            t = q.back();
                        }
                        
                    }
                    q.push_back(a[i]);
                }
            }
            i++;
        }
        while(!q.empty())
        {
            vec.push_back(q.front());
            q.pop_front();
        }
        return vec;
    }
};

Problem Link: https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/#
--------------------------------------------------------------------------------------------------------------
  
  
 
class Solution {
  public:
    int LIS(vector<int> A)
    {
        int n = A.size();
        vector<int> activeseq;
        for(int i=0;i<n;i++)
        {
            auto lb = lower_bound(activeseq.begin(), activeseq.end(), A[i]);
            if(lb!=activeseq.end())
            {
                *lb = min(*lb, A[i]);
            }
            else
            {
                activeseq.push_back(A[i]);
            }
        }
        return activeseq.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        unordered_set<int> b_set;
        for(int i=0;i<M;i++)
        {
            b_set.insert(B[i]);
        }
        vector<int> a_update;
        int steps = 0;
        for(int i=0;i<N;i++)
        {
            if(b_set.find(A[i])!=b_set.end())
            {
                a_update.push_back(A[i]);
            }
            else
            {
                steps++;
            }
        }
        
        int s = LIS(a_update);
        return steps+(a_update.size()-s)+(M-s);
    }
};

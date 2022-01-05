problem link: https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1/#
--------------------------------------------------------------------------------------------------


class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        if((M+K-1)<N)
        {
            return M+K-1;
        }
        else if((M+K-1)>N)
        {
            int a =M+K-1-N; 
            while(a>N)
            {
                a = a-N;
            }
            return a;
        }
    }
};

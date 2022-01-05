Problem Link: https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/#


class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        //considering non overlapping case
        if(R1[0]<L2[0] or R2[0]<L1[0])
        {
            return 0;
        }
        else if(R2[1]>L1[1] or R1[1]>L2[1])
        {
            return 0;
        }
        return 1;
    }
};

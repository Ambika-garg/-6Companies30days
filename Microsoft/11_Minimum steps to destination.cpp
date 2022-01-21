Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/
----------------------------------------------------------------------------------------------------------------
  
  
  
class Solution{
public:
    
    int minSteps(int D){
        int steps = 0;
        int sum = 0;
        
        while(sum<D || (sum - D)%2!=0)
        {
            sum = sum+steps;
            steps++;
        }
        return steps-1;
    }
};

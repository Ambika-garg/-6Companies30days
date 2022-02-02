Problem Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int cal_turns(string colors, char c)
    {
        int ans = 0;
        int count = 0;
        for(auto &x: colors)
        {
            
            if(x==c)
            {
                count++;
            }
            if(x!=c)
            {
                if(count>=3)
                {
                    ans+=count-2;
                }
                count = 0;
            }
            
        }
        if(count>=3)
        {
            ans = ans+count-2;
        }
        return ans;
    }
    bool winnerOfGame(string colors) {
        if(colors.length()<3)
        {
            return false;
        }
        int a = cal_turns(colors, 'A');
        int b = cal_turns(colors, 'B');
        return a>b;
    }
};

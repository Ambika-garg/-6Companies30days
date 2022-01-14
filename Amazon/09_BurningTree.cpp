Problem Link: https://practice.geeksforgeeks.org/problems/burning-tree/1/#
-----------------------------------------------------------------------


class Solution {
  public:
    int maxTime=0;
    void heightsubtree(Node* root, int t)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            // cout<<root->data<<" : "<<"time: "<<maxTime<<endl;
            maxTime = max(maxTime, t);
            heightsubtree(root->left, t+1);
            heightsubtree(root->right, t+1);
        }
    }
    
    int maxdistanceup(Node* root, int target)
    {
        if(!root)
        {
            return -1;
        }
        else if(root->data==target)
        {
            heightsubtree(root, 0);
            return 0;
        }
        else
        {
            
            int dl = maxdistanceup(root->left, target);
            if(dl!=-1)
            {
                heightsubtree(root->right, dl+2);
                return dl+1;
            }
            
            int dr = maxdistanceup(root->right, target);
            if(dr!=-1)
            {
                heightsubtree(root->left, dr+2);
                return dr+1;
            }
            return -1;
        }
    }
    int minTime(Node* root, int target) 
    {
        maxdistanceup(root, target);
        return maxTime;
    }
};

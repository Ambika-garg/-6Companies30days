Problem Link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/
------------------------------------------------------------------------------------
  
  
  
  class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int findsum(Node* temp, Node* node)
    {
        if(temp==NULL or node==NULL)
        {
            return 0;
        }
        else
        {
            int leftsum = findsum(temp->left, node);
            int rightsum = findsum(temp->right, node);
            int a = temp->data+leftsum+rightsum;
            temp->data = leftsum+rightsum;
            return a;
        }
    }
    void toSumTree(Node *node)
    {
        Node* temp = node;
        int a = findsum(temp, node);
        return;
    }
};

Problem Link: https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1#
------------------------------------------------------------------------------------------------------
  
  
  
 class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> vec;
    void inorder(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            inorder(root->left);
            vec.push_back(root->data);
            inorder(root->right);
        }
    }
    vector<int> serialize(Node *root) 
    {
        inorder(root);
        return vec;
    }
    Node* maketree(vector<int> &A, int& v)
    {
        if(A.size()==0 or v==A.size())
        {
            return NULL;
        }
        else
        {
            Node* root = new Node(A[v]);
            v = v+1;
            root->right = maketree(A, v);
            root->left = maketree(A, v);
            return root;
        }
    }
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       int v = 0;
       Node* root = maketree(A, v);
       return root;
    }

};

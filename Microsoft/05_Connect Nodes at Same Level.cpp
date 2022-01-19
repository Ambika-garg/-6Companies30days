Problem Link: https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/#



class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       if(root==NULL)
       {
           return;
       }
       else if(root->left==NULL and root->right==NULL)
       {
           root->nextRight=NULL;
           return ;
       }
       else
       {
           queue<Node*> q;
           q.push(root);
           q.push(NULL);
           Node* temp = root;
           while(!q.empty())
           {
               temp = q.front();
               if(temp!=NULL)
               { 
                   if(temp->left)
                   {
                       q.push(temp->left);
                   }
                   if(temp->right)
                   {
                       q.push(temp->right);
                   }
                   q.pop();
                   
                   Node* t = q.front();
                   temp->nextRight=t;
               }
               else
               {
                   q.pop();
                   if(!q.empty())
                   {
                       q.push(NULL);
                   }
                   
               }
           }
           return;
       }
    }    
      
};

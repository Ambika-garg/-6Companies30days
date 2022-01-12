Problem Link: https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/#
------------------------------------------------------------------------------------------------------------



class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(head==NULL)
        {
            return;
        }
        else
        {
            int i = 1;
            Node* temp = head;
            while(i!=M and temp!=NULL)
            {
                temp = temp->next;
                i++;
            }
            
            int j=0;
            if(temp!=NULL and temp->next!=NULL)
            {
                while(j!=N and temp->next!=NULL)
                {
                    Node* tobedel = temp->next;
                    temp->next = temp->next->next;
                    tobedel = NULL;
                    delete tobedel;
                    j++;
                }
                // cout<<"a: "<<temp->data<<" ";
                linkdelete(temp->next, M, N);
            }
            
            
        }
        return;
    }
};


Problem Link: https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/#
-----------------------------------------------------------------------------------------------------------



int countsubtree(Node* root, int X, int& ans)
{
    if(root==NULL)
	{
	    return 0;
	}
	
	int left_tree_sum = countsubtree(root->left, X, ans);
	int right_tree_sum = countsubtree(root->right, X, ans);
	
	int sum = root->data+left_tree_sum+right_tree_sum;
	if(sum==X)
	{
	    ans++;
	}
	return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
    int ans = 0;
	countsubtree(root, X, ans);
	return ans;
}

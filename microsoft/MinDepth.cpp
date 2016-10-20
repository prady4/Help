/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A->left==NULL && A->right == NULL)
        return 1;
    
    int a = 0, b = 0;
    
    if(A->left!=NULL)
        a = minDepth(A->left);
    
    if(A->right != NULL)
        b = minDepth(A->right);
    
    if(!a)
        return b+1;
    if(!b)
        return a+1;
    else
        return min(a,b)+1;
}

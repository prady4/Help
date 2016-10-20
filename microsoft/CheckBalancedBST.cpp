/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
int height(TreeNode* A){
    if(A==NULL)
        return 0;
    else{
        int a = height(A->left);
        if(a == -1)
            return -1;
        int b = height(A->right);
        if(b == -1)
            return -1;
        if(abs(a-b) > 1)
            return -1;
        else
            return max(a,b)+1;
        
    }
    
}
int Solution::isBalanced(TreeNode* A) {
    if(height(A) != -1)
        return 1;
    return 0;
}


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* helper(vector<int> &A, vector<int> &B, int low, int high, int &index){
    //static int index = 0;
    if(low > high)
        return NULL;
    TreeNode* node = new TreeNode(B[index]);
    int mid;
    for(int i = low; i <= high; i++){
        if(B[index] == A[i]){
            mid = i;
            break;
        }
    }
    index++;
    
    node->left = helper(A, B, low, mid - 1, index);
    node->right = helper(A, B, mid + 1, high, index);
    
    return node;
    
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    int index = 0;
    return helper(inorder, preorder, 0, inorder.size()-1, index);
}

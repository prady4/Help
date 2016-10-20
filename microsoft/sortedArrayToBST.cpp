TreeNode* helper(const vector<int> &A, int low, int high) {
    /*
    if(low==high){
        TreeNode* node = new TreeNode(A[low]);
        return node;
    }
    int mid = (low+high)/2;
    TreeNode* node = new TreeNode(A[mid]);
    if(mid!=low)
        node->left = helper(A, low, mid-1);
    node->right = helper(A, mid+1, high); 
    return node;
    */
        if (low > high) {
            return NULL;
        }
        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(A[mid]);
        node->left = helper(A, low, mid - 1);
        node->right = helper(A, mid + 1, high);
        return node;
        
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if(!A.size())
        return NULL;
    return helper(A, 0, A.size()-1);
}
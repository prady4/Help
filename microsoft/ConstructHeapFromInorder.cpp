TreeNode* Solution::buildTree(vector<int> &A) {
    
    int l = A.size();
    if(l==0)
        return NULL ;
    else if(l== 1)
    {
        TreeNode* node = new TreeNode(A[0]);
        return node;
    }
    int index = distance(A.begin(), max_element(A.begin(), A.end()));
    TreeNode* node = new TreeNode(A[index]);
        vector<int> B(A.begin(), A.begin() + (index));
        vector<int> C(A.begin() + (index + 1), A.end());
       
        node->left = buildTree(B);
        node->right = buildTree(C); 
    return node;
    
}
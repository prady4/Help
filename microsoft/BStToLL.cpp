TreeNode* Solution::flatten(TreeNode* A) {
    
        TreeNode* temp  = NULL,  *p = NULL;
        if(A->left){
            temp = flatten(A->left);
            p = temp;
            while(p->right != NULL)
                p = p->right;
        }
        if(A->right)
            if(p != NULL)
                p->right = flatten(A->right);
            else
                temp = flatten(A->right);
        A->left = NULL;
        A->right = temp;
        return A;

}
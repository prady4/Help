/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> s ;
    vector<int>result ;
    if(A == NULL)
        return result ;
    TreeNode *top1 , *top2 ;
    s.push(A);
    s.push(A);
    while(!s.empty())
    {
        top1 = s.top() ;
        s.pop() ;
        top2 = NULL ;
        if(!s.empty())
            top2 = s.top() ;
        if(top1 == top2)
        {
            result.push_back(top1->val) ;
            if(top1->left != NULL)
            {
                s.push(top1->left) ;
                s.push(top1->left) ;
            }
        }
        else
        {
            if(top1->right != NULL)
            {
                s.push(top1->right) ;
                s.push(top1->right) ;
            }
        }
    }
    return result ;
}

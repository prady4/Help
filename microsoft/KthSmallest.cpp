/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int k) {
    stack<TreeNode*> s ;
    int count = 0;

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
        if(top1 != top2)
        {
            
            count++;
            if(count == k)
                return top1->val;
            if(top1->right != NULL)
            {
                s.push(top1->right) ;
                s.push(top1->right) ;
            }
        }
        else
        {
            
            if(top1->left != NULL)
            {
                s.push(top1->left) ;
                s.push(top1->left) ;
            }
            
        }
    }
}

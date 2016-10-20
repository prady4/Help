/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode*> s;

BSTIterator::BSTIterator(TreeNode *root) {
    if(!root)
        return;
    s.push(root);
    s.push(root);
    TreeNode* top1;
    TreeNode* top2;
    while(!s.empty()){
        top1 = s.top() ;
        s.pop() ;
        if(top1->left==NULL)
            break;
        top2 = NULL ;
        if(!s.empty())
            top2 = s.top() ;
        if(top1 == top2)
        {
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
    return;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    //cout<<"hasbeencalled"<<endl;
    //cout<<s.empty()<<endl;
    if(s.empty())
        return false;
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* top1;
    TreeNode* top2= NULL;
    top1 = s.top();
    s.pop();
    if(!s.empty())
        top2 = s.top();
    if(top1 != top2){
        if(top1->right)
            BSTIterator(top1->right);
        return top1->val;
        //next();
        
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

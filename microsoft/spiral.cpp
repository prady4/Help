/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxDepth(TreeNode* A) {
    if(A==NULL)
        return 0;
    else{
        int a = maxDepth(A->left);
        int b = maxDepth(A->right);
        return max(a,b)+1;
    }
}

void helper(TreeNode* A, int level, bool l, vector<int> &vec){
    if(!A)
        return;
    if(level == 1){
        vec.push_back(A->val);
        return;
    }
    else{
        if(l){
            helper(A->right, level-1, l, vec);
            helper(A->left, level-1, l, vec);
        }
        else{
            helper(A->left, level-1, l, vec);
            helper(A->right, level-1, l, vec);
        }
    }
    
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > v;
    if(!A)
        return v;
    if(A->left == NULL && A->right == NULL){
        vector<int> vec;
        vec.push_back(A->val);
        v.push_back(vec);
        return v;
    }
    int x = maxDepth(A);
    bool l = false;
    for(int i = 1; i <= x; i++){
        vector<int> vec;
        helper(A,i, l, vec);
        v.push_back(vec);
        l = !l;
    }
}

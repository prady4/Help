void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    q.push(A);
    q.push(NULL);
    TreeLinkNode* front;
    while(!q.empty()){
        front = q.front();
        q.pop();
        if(front == NULL){
            if(q.empty())
                return;
            else
                q.push(NULL);
        }
        else{
            if(front->left != NULL)
                q.push(front->left);
            if(front->right  != NULL)
                q.push(front->right);
            front->next = q.front();
        }
    }
}
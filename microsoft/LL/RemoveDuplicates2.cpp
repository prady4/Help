/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* p = A, *q = NULL;
    if(!p->next)
        return p;
    if(!p->next)
        return p;
    q = p;
    p = p->next;  
    while(p){
        if(p->val == q->val){
            q->next = p->next;
            p = p->next;
        }
        else{
            q = p;
            p = p->next;
        }
    }
    return A;
}

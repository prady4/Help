/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* p = A, *q = A, *r = NULL;
    if(!p)
        return p;
    while(p){
        if(p->val >= B)
            break;
        q = p;
        p = p->next;
    }
    if(!p)
        return A;
    r = p;
    p = p->next;
    while(p){
        if(p->val < B){
            r->next = p->next;
            if(q->val >= B){
                p->next = A;
                A = p;
                q = A;
            }
            else{
                p->next = q->next;
                q->next = p;
                q = p;
            }
            p = r->next;
        }
        else{
            r = p;
            p = p->next;
        }
    }
    return A;
}

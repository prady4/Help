/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* A) {
    if(!A->next)
        return A;
    ListNode* p = A, *q = NULL, *temp = NULL, *r, *e;
    
    while(p){
        e = p->next;
        p->next = temp;
        temp = p;
        p = e;
    }
    return temp;
}

ListNode* Solution::reorderList(ListNode* A) {
    if(!A || !A->next)
        return A;
    ListNode* p = A, *q = A, *temp = A, *r;
    while(p->next && p->next->next){
        q = q->next;
        p = p->next->next;
    }
    p = q->next;
    q->next = NULL;
    q = reverse(p);
    p = A;
    while(q){
        r = q->next;
        q->next = p->next;
        p->next = q;
        p = q->next;
        q = r;
    }
    return A;
}

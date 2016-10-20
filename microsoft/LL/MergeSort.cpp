/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* A, ListNode* B) {
    ListNode* p, *q;
    if(!A)
        return B;
    if(!B)
        return A;
    if(A->val > B->val){
       p = B;
       B = B->next;
    }
    else{
       p = A;
       A = A->next;
    }
    q = p;
    while(A && B){
        if(A->val > B->val){
            q->next = B;
            q = B;
            B = B->next;
            q->next = NULL;
        }
        else{
            q->next = A;
            q = A;
            A = A->next;
            q->next = NULL;
        }
    }
    if(!A)
        q->next = B;
    if(!B)
        q->next = A;
    return p;
}

ListNode* Solution::sortList(ListNode* A) {
    if(!A || !A->next)
        return A;
    else if(!A->next->next){
        int temp = 0;
        if(A->val > A->next->val){
            temp = A->val;
            A->val = A->next->val;
            A->next->val = temp;
        }
        return A;
    }
    else{
        ListNode* p = A, *q = A;
        while(p->next && p->next->next){
            q = q->next;
            p = p->next->next;
        }
        p = q->next;
        q->next = NULL;
        return merge(sortList(A),sortList(p));
    }
}

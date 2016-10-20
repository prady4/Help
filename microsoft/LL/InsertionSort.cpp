/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* insert(ListNode* A, ListNode* B){
    ListNode*p, *q;
    if(A->val > B->val){
        B->next = A;
        A = B;
        return A;
    }
    q = A;
    p = A->next;
    while(p){
        if(p->val >= B->val){
            B->next = q->next;
            q->next = B;
            return A;
        }
        q = p;
        p = p->next;
    }
    q->next = B;
    return A;
}

ListNode* Solution::insertionSortList(ListNode* A) {
    if(!A || !A->next)
        return A;
    if(!A->next->next){
        int temp = 0;
        if(A->val > A->next->val){
            temp = A->val;
            A->val = A->next->val;
            A->next->val = temp;
        }
        return A;
    }
    ListNode* temp = A, *p, *q;
    p = A->next;
    A->next = NULL;
    while(p){
        q = p;
        p = p->next;
        q->next = NULL;
        temp = insert(temp, q);
    }
    return temp;
}

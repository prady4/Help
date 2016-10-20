/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *fast, *slow;
    if(!A || !A->next)
        return A;
    fast = A->next->next;
    slow = A->next;
    while (fast != slow && fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }       
    if(fast != slow)
        return NULL;
    if(fast == A)
        return A;
    fast = A;
    while (fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

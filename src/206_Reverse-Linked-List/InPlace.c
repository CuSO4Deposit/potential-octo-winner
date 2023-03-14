// https://leetcode.com/problems/reverse-linked-list/solutions/3211778/using-2-methods-iterative-recursive-beats-97-91/
// 0 ms (< 100%), 6.5 MB(< 46.25%)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    
    if (cur == NULL)    return NULL;

    while (cur->next != NULL){
        struct ListNode* forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    cur->next = prev;


    return cur;
}

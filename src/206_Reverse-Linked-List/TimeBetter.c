// 0 ms (< 100%), 6.5 MB (< 19.77%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    int vals[5000];
    struct ListNode* p = head;
    int idx = -1;
    while (p != NULL){
        vals[++idx] = p->val;
        p = p->next;
    }

    if (idx == -1)  return NULL;

    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->val = vals[idx];
    struct ListNode* last = newHead;

    while (idx > 0){
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = vals[--idx];
        last->next = p;
        last = p;
    }
    last->next = NULL;

    return newHead;
}

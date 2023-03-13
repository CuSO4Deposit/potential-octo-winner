// 4 ms (< 44.46%), 6.2 MB(< 37.80%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL)  return list2;
    if (list2 == NULL)  return list1;
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    struct ListNode* start = NULL;
    if (p1->val < p2->val){
        start = p1;
        p1 = p1->next;
    }
    else{
        start = p2;
        p2 = p2->next;
    }
    struct ListNode* end = start;

    while (p1 && p2){
        if (p1->val < p2->val){
            end->next = p1;
            end = p1;
            p1 = p1->next;
        }
        else{
            end->next = p2;
            end = p2;
            p2 = p2->next;
        }
    }

    if (p1 != NULL){
        end->next = p1;
    }
    else{
        end->next = p2;
    }
    return start;
}

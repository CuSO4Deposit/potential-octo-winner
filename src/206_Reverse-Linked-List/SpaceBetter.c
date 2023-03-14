// TLE

struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL){
        return NULL;
    }

    struct ListNode* newHead = head;
    while (newHead->next != NULL){
        newHead = newHead->next;
    }

    struct ListNode* p = head;
    struct ListNode* newEnd = newHead;
    while (newEnd != head){
        while (p->next != newEnd){
            p = p->next;
        }
        newEnd->next = p;
        newEnd = p;
        p = head;
    }

    return newHead;
}

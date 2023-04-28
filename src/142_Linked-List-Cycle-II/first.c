// 6 ms (< 64.86%), 7.3 MB (< 26.22%)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* fsTraverse(struct ListNode* list, int* n){
	// return the node where fast and slow pointer meets
	// (*n) records the # of steps the slow pointer goes
	struct ListNode* f = list;
	struct ListNode* s = list;
	*n = 0;
	while (1){
		if (f == NULL)
			return NULL;
		f = f->next;
		if (f == NULL)
			return NULL;
		s = s->next;
		(*n)++;
		f = f->next;

		if (f == s)
			return f;
	}
}

struct ListNode *detectCycle(struct ListNode *head) {
	int Ls = 0; 
	struct ListNode* meet = fsTraverse(head, &Ls);
	if (meet == NULL)
		return NULL;
	int Lc = 0;
	fsTraverse(meet, &Lc); // Lc is the length of the circle.
	int n = Ls / Lc;

	struct ListNode* p = head;
	for (size_t i = 0; i < (n - 1) * Lc; i++) {
		p = p->next;
	}

	while (p != meet){
		p = p->next;
		meet = meet->next;
	}
	return p;
}

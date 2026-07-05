/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    int length = 1;
    struct ListNode * current = head;
    while (current->next != NULL) {
        length++;
        current = current->next;
    }
    current->next = head;
    current = current->next;
    int index = 0;
    int target = length - (k % length) - 1;
    while (current->next != NULL) {
        if (index == target) {
            struct ListNode * answer = current->next;
            current->next = NULL;
            return answer;
        }
        index++;
        current = current->next;
    }
    return NULL;
}

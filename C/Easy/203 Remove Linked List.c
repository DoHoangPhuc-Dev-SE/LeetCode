/*
LC 203 - Remove Linked List Elements
Link: https://leetcode.com/problems/remove-linked-list-elements/
Hours Effort: 00:15:13
Solution: Skip leading matching head nodes & re-link pointers in-place
Time: O(n), Space: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) head = head->next;
    struct ListNode* p = head;
    while(p != NULL && p->next != NULL){
        if(p->next->val == val) {
            p->next = p->next->next;
        } else {
            p = p->next;
        }
    }
    return head;
}
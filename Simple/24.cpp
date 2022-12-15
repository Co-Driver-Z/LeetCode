/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 1) Ref 206题，反转链表
        ListNode* Pre = NULL;
        ListNode* Cur = head;
        while (Cur != NULL) {
            ListNode* Temp = Cur->next;
            Cur->next = Pre;
            Pre = Cur;
            Cur = Temp;
        }
        return Pre;
    }
};
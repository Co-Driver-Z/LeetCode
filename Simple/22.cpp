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
    // 思路: 求解链表倒数第 K 个节点的问题（双指针思路）
    // PosCur 指针指向当前节点
    // PosAns 指针维护待返回的答案的首指针
    // 直到PosCur遍历到最后一个节点（PosCur->next == NULL）
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 1) 初始化两个指针
        ListNode* PosCur = head;
        ListNode* PosAns = head;
        for (int i = 0; i < k-1; ++i) {
            PosCur = PosCur->next;
        }
        // 2) 遍历指针
        while (PosCur->next) {
            PosCur = PosCur->next;
            PosAns = PosAns->next;
        }
        return PosAns;
    }
};
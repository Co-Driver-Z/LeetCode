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
    // 思路: 考察删除单链表中的某一个节点，采用双指针方法
    // 1) 从头节点遍历单链表，直至下一个节点的值为目标值
    // 2) PosCur指针指向当前节点地址
    //    PosNNe指针指向下下节点地址
    // 3) PosCur->next = PosNNe;
    ListNode* deleteNode(ListNode* head, int val) {
        // 0) 如果为空的单链表
        if (head == NULL)
            return head;
        // 1) 如果要删除的目标节点为首节点
        if (head->val == val)
            return head->next;
        // 2) 如果要删除的目标节点为后续节点则
        ListNode* PosCur = head;
        while (PosCur) {
            if (PosCur->next->val == val) {
                PosCur->next = PosCur->next->next;
                break;
            }
            PosCur = PosCur->next;
        }
        return head;
    }
};
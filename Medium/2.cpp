/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1、创建一个答案链表
        int TensNum = 0, OnesNum = 0, Num1 = 0, Num2 = 0;
        ListNode* Result = new ListNode;
        ListNode* TempPos = Result;
        // 2、按最长的链表逐位进行相加
        while (l1 || l2 || TensNum) {
            if (!l1 && !l2)
                Num1 = 0, Num2 = 0;
            else if (!l1) 
                Num1 = 0, Num2 = l2->val, l2 = l2->next;
            else if (!l2) 
                Num1 = l1->val, Num2 = 0, l1 = l1->next;
            else
                Num1 = l1->val, Num2 = l2->val, l1 = l1->next, l2 = l2->next;
            OnesNum = (Num1 + Num2 + TensNum)%10;
            TensNum = (Num1 + Num2 + TensNum)/10;
            TempPos->val = OnesNum;
            if (l1 || l2 || TensNum) {
                TempPos->next = new ListNode;
                TempPos = TempPos->next;
            }
        }
        // 3、返回答案
        return Result;
    }
};
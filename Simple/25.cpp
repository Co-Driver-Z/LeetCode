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
    // 思路1: 同时遍历单链表1和单链表2，创建一个新的单链表用于返回答案
    // 1) 同时遍历 单链表1 和 单链表2 采用 While循环
    // 2) While循环里面套三 IF 语句，用于判断哪个链表先到头
    // 该思路的时间复杂度和空间复杂度均较高，建议采用思路2递归的思想
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     // 1) 创建一个新的单链表
    //     ListNode* NewList = NULL;
    //     ListNode* Ans = NULL;
    //     // 2) 对两个单链表进行循环
    //     while (l1 || l2) {
    //         ListNode* Temp = new ListNode;
    //         // 2.1) 如果 l1 和 l2 都不为空
    //         if (l1 && l2) {
    //             if (l1->val < l2->val) {
    //                 Temp->val = l1->val;
    //                 l1 = l1->next;
    //             }
    //             else {
    //                 Temp->val = l2->val;
    //                 l2 = l2->next;
    //             }
    //         }
    //         // 2.2) 如果 l1 不为空
    //         else if (l1) {
    //             Temp->val = l1->val;
    //             l1 = l1->next;
    //         }
    //         // 2.3) 如果 l2 不为空
    //         else {
    //             Temp->val = l2->val;
    //             l2 = l2->next;
    //         }
    //         if (NewList == NULL) {
    //             NewList = Temp;
    //             Ans = Temp;
    //         }
    //         else {
    //             NewList->next = Temp;
    //             NewList = Temp;
    //         }
    //     }
    //     return Ans;
    // }

    // 思路2: 递归思想
    // 原题目可以划分为相同的子问题:
    // IF List1[i] < List2[j]
    // Ans = List1[i] -> mergeTwoLists(List1[i+1], List2[j])
    // ELSE
    // Ans = List2[j] -> mergeTwoLists(List1[i], List2[j+1])
    // 注意终止条件为: 如果List1或List2有一个到尾部即可结束，因为两个单链表均为递增的单链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else {
            if (l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }
};
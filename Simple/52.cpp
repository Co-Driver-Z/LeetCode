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
    // 思路: 题目要求程序尽量满足O(N)时间复杂度 Or 仅仅使用O(1)空间复杂度
    // 1) 可采用使用双指针分别遍历单链表1和单链表2，并使用 Hash 表来存储遍历过的地址
    // 2) 直到遇到与Hash相同地址返回答案，否则返回NULL
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 1) 设置双指针 + Hahs表
        ListNode* Pos1 = headA;
        ListNode* Pos2 = headB;
        std::unordered_set<ListNode*> Hash;
        // 2) 使用 While 循环进行遍历
        while (Pos1 || Pos2) {
            if (Pos1) {
                if (Hash.find(Pos1) != Hash.end())
                    return Pos1;
                Hash.insert(Pos1);
                Pos1 = Pos1->next;
            }
            if (Pos2) {
                if (Hash.find(Pos2) != Hash.end())
                    return Pos2;
                Hash.insert(Pos2);
                Pos2 = Pos2->next;
            }
        }
        return NULL;
    }
};
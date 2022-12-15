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
    vector<int> reversePrint(ListNode* head) {
        // 1) 如果 head 为空则返回空
        if (head == NULL)
            return {};
        // 2) 如果 head 不为空
        std::vector<int> PreAns;
        std::vector<int> Ans;
        while (head) {
            PreAns.push_back(head->val);
            head = head->next;
        }
        // 3) 反转结果
        for (std::vector<int>::reverse_iterator it = PreAns.rbegin(); it != PreAns.rend(); ++it)
            Ans.push_back(*it);
        return Ans;
    }
};
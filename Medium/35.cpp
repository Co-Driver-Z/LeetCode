/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    Node* copyRandomList(Node* head) {
        // 0) 遍历链表获取链表的长度 ListLen，同时创建一个Hash表存储Random对应的索引
        int ListLen = 0;
        std::unordered_map<Node*, int> Hash;
        Node* Temp = head;
        while (Temp != NULL) {
            Hash[Temp] = ListLen;
            ListLen += 1;
            Temp = Temp->next;
        }
        // 1) 创建一个指针数组用于存储相应索引的节点指针
        std::vector<Node*> Address(ListLen+1, NULL);
        // 2) 第一次循环先将节点属性构建好
        Node* head_ = head;
        for (int i = 0; i < ListLen; ++i) {
            Node* Temp = new Node(head_->val);
            Address[i] = Temp;
            head_ = head_->next;
        }
        // 3) 第二次循环将next地址和Random地址构建好
        head_ = head;
        for (int i = 0; i < ListLen; ++i) {
            Address[i]->next = Address[i+1];
            if (head_->random == NULL)
                Address[i]->random = NULL;
            else
                Address[i]->random = Address[Hash[head_->random]];
            head_ = head_->next;
        }
        return Address[0];
    }
};
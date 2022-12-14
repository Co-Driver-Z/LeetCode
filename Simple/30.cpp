class MinStack {
public:
    // 方法1: 使用链表的数据结构定义栈
    /** initialize your data structure here. */
    // 链表的节点数据类型
    struct ListNode {
    public:
        int Num = 0;
        int MinNum = 0;
        ListNode() = default;
        ListNode(int Num_, int MinNum_): Num(Num_), MinNum(MinNum_) {};
        ListNode* Next = nullptr;
        ListNode* Prev = nullptr;
    };
    typedef ListNode* ListPos;

    ListPos PrePos = nullptr;
    ListPos CurPos = nullptr;
    MinStack() {
        PrePos = new ListNode();
        CurPos = PrePos;
    }
    
    void push(int x) {
        // 1) 如果添加的为链表的第一个元素
        if (CurPos == PrePos) {
            ListPos NewPos = new ListNode(x, x);
            PrePos->Next = NewPos;
            CurPos = NewPos;
            CurPos->Prev = PrePos;
        }
        // 2) 如果添加的不为链表的第一个元素
        else {
            ListPos NewPos = new ListNode(x, x < CurPos->MinNum ? x : CurPos->MinNum);
            ListPos Temp = CurPos;
            CurPos->Next = NewPos;
            CurPos = NewPos;
            CurPos->Prev = Temp;
        }
    }
    
    void pop() {
        // 1) 如果链表为空则不删除
        if (CurPos == PrePos)
            return;
        // 2) 如果链表不为空
        ListPos Temp = CurPos;
        CurPos = CurPos->Prev;
        delete Temp;
    }
    
    int top() {
        return CurPos->Num;
    }
    
    int min() {
        return CurPos->MinNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
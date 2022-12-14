class CQueue {
public:
    std::stack<int> S1;  // 用于存储队列Head
    std::stack<int> S2;  // 用于以此存储队列的其他元素
    CQueue() {
    }
    
    void appendTail(int value) {
        // 1) S1若为空->（队列为空)则直接插入S1
        if (S1.empty())
            S1.push(value);
        // 2) S1不为空-> (队列不空)则直接插入S2尾部
        else
            S2.push(value);
    }
    
    int deleteHead() {
        // 0) 如果队列为空则返回 -1
        if (S1.empty())
            return -1;
        // 1) 弹出S1的唯一一个元素(作为返回值)
        int Ans = S1.top();
        S1.pop();
        // 2) 若S2为空则直接返回，从S2倒序插入S1中，并弹出插入后的栈顶临时存储，再将S1倒叙插入S2(纠正顺序)
        if (S2.empty())
            return Ans;
        while(!S2.empty()) {
            int Temp = S2.top();
            S1.push(Temp);
            S2.pop();
        }
        int TempNum = S1.top();
        S1.pop();
        while(!S1.empty()) {
            int Temp = S1.top();
            S2.push(Temp);
            S1.pop();
        }
        // 3) 将临时储存的数字插入S1作为Head
        S1.push(TempNum);
        // 4) 返回Ans
        return Ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
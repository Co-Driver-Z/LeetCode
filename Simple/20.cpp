class Solution {
public:
    bool isValid(string s) {
        // 1、创建一个vector模拟栈、创建一个unordered_map用于存储相同括号的对应关系
        int SearchPos = 0;
        std::string Stack;
        std::unordered_map<char, char> HashMap;
        HashMap['('] = ')'; HashMap['{'] = '}'; HashMap['['] = ']';
        // 2、遇到左括号： ( { [ 则入栈，遇到右括号则检测栈顶，相同则出栈，否则返回false
        for (const auto& C : s) {
            if (C == '(' || C == '{' || C == '['){
                Stack.push_back(C);
            }
            else {
                if (C == HashMap[Stack.back()])
                    Stack.pop_back();
                else    
                    return false;
            }
            ++SearchPos;
        }
        // 3、若s遍历完，且栈为空，则返回true
        if (SearchPos == s.size() && Stack.empty())
            return true;
        else   
            return false;
    }
};
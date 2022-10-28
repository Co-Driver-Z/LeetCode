class Solution {
public:
    int minOperations(vector<string>& logs) {
        // 0如果logs为空返回 0
        if (logs.size() == 0)
            return 0;
        // 1、创建一个Stack用于表示当前位于第几层文件夹
        std::stack<int> Stack;
        // 2、遍历 logs 
        for (auto const& s : logs) {
            if (s == "./") 
                continue;
            else if (s == "../"){
                if (!Stack.empty())
                 Stack.pop();
            }
            else
                Stack.push(1);
        }
        // 3、返回结果
        return Stack.size();
    }
};
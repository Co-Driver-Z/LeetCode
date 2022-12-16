class Solution {
public:
    // 分析: 整体思路很简单:
    // 1、获取前 n 个字符
    // 2、进行 sub和拼接操作
    string reverseLeftWords(string s, int n) {
        // 1) 获取前 n 个字符
        std::string Temp = s.substr(0, n);
        // 2) 进行 sub 和 拼接操作
        return s.substr(n) + Temp;
    }
};
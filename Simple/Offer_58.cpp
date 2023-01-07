class Solution {
public:
    // 思路: 反转单词顺序，核心在于对于句子单词的分割，即遇到空格则分割
    // 1) 遍历 s，遇到空格则分割单词，并添加至 vecotr 中
    // 2) 对于 vector 倒序输出（同时加上单个空格）
    string reverseWords(string s) {
        // 1) 初始化答案、vector
        std::string Ans;
        std::vector<std::string> V;
        // 2) 遍历 s 分割单词
        s += " ";
        std::string Word;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (Word != "") {
                    V.push_back(Word);
                    Word = "";
                }
                continue;
            }
            Word = Word + s[i];
        }
        // 3) 对 V 倒序输出答案
        for (std::vector<std::string>::reverse_iterator it = V.rbegin(); it != V.rend(); ++it) {
            Ans += *it;
            if (it != V.rend() - 1)
                Ans += " ";
        }
        return Ans;
    }
};
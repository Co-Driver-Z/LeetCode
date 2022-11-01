class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // 1、初始化相关变量
        int Result = 0;
        std::unordered_map<char, int> Hash;  // 存储 '字符' -> 个数
        for (int i = 0; i < chars.size(); ++i)
            ++Hash[chars[i]]; 
        // 2、循环遍历
        for (auto const& S : words) {
            std::unordered_map<char, int> Hash_ = Hash;
            for (int i = 0; i < S.size(); ++i) {
                if (!Hash_.count(S[i]) || !Hash_[S[i]])
                    break;
                else {
                    --Hash_[S[i]];
                }
                if (i == S.size()-1)
                    Result += S.size();
            }
        }
        return Result;
    }
};
class Solution {
public:
    int countVowelSubstrings(string word) {
        // 1、定义初始状态
        int Result = 0;
        // 2、遍历整个数组        
        for (int i = 0; i < word.size(); ++i) {
            int State = 0;
            for (int j = i; j < word.size(); ++j) {
                if (word[j] == 'a') State |= 1;
                else if (word[j] == 'e') State |= 2;
                else if (word[j] == 'i') State |= 4;
                else if (word[j] == 'o') State |= 8;
                else if (word[j] == 'u') State |= 16;
                else break;
                if (State == 31)
                    ++Result;
            }
        }
        return Result;
    }
};
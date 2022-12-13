class Solution {
public:
    bool checkIfPangram(string sentence) {
        // 1) 初始化每个字符出现的次数数组
        std::vector<int> Num(26);
        // 2) 遍历 sentence
        int Count = 0;
        for (const auto& C : sentence) {
            if (!Num[(int)(C - 'a')]) {
                Num[(int)(C - 'a')] = 1;
                Count++;
            }
        }
        // 3) Output
        if (Count == 26)
            return true;
        return false;
    }
};
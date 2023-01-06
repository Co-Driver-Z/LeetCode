class Solution {
public:
    // 对于求解最长“子串”的问题，可采用双指针的滑动窗口方法:
    // 1) 左指针开始指向S的 Pos0 位置，右指针指向 Pos0 位置，左指针开始从S的0往后遍历
    // 2) 右指针不断向后面扩展，如果遇到相同的元素则将左指针右移动（判断是否遇到相同的元素可以使用Hash表）
    //    左指针采用 For   循环
    //    右指针采用 While 循环
    int lengthOfLongestSubstring(string s) {
        // 1) 初始化Hash表和左指针、右指针
        std::unordered_set <char> Hash;
        int LPos = 0; int RPos = 0; int Ans = 0;
        // 2) 左指针 For 循环、 右指针 While 循环
        for (; LPos < (int)s.size(); ++LPos) {
            while (RPos < (int)s.size() && Hash.find(s[RPos]) == Hash.end()) {
                Hash.insert(s[RPos]);
                Ans = max(Ans, RPos - LPos + 1);
                ++RPos;
            }
            Hash.erase(s[LPos]);
        }
        // 3) 返回结果
        return Ans;
    }
};
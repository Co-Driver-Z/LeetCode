class Solution {
public:
    bool JudgePalindromString(std::string S, int Low, int High) {
        for (int i = Low, j = High; i < j; ++i, --j) {
            if (S[i] != S[j])
                return false;
        }
        return true;
    };
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return (JudgePalindromString(s, i+1, j) || JudgePalindromString(s, i, j-1));
            ++i, --j;
        }
        return true;
    }
};
// 1、双指针法
class Solution {
public:
    bool isPalindrome(string s) {
        int Len = s.size();
        int LPos = 0;
        int RPos = Len - 1;
        while (LPos != RPos && LPos < RPos) {
            if (isalnum(s[LPos]) && isalnum(s[RPos]) && tolower(s[LPos]) != tolower(s[RPos]))
                return false;
            else if (!isalnum(s[LPos]) && isalnum(s[RPos]))
                ++LPos;
            else if (isalnum(s[LPos]) && !isalnum(s[RPos]))
                --RPos;
            else {
                ++LPos;
                --RPos;
            }
           ;
        }
        return true;
    }
};
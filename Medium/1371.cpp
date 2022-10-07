class Solution {
public:
    int findTheLongestSubstring(string s) {
        int MaxLen = 0;
        int State = 0;
        vector<int> FirstStatePos(32, INT_MAX);
        FirstStatePos[0] = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a')
                State ^= 1;
            else if (s[i] == 'e')
                State ^= 2;
            else if (s[i] == 'i')
                State ^= 4;
            else if (s[i] == 'o')
                State ^= 8;
            else if (s[i] == 'u')
                State ^= 16;
            if (FirstStatePos[State] == INT_MAX)
                FirstStatePos[State] = i;
            else 
                MaxLen = std::max(MaxLen, i - FirstStatePos[State]);
        }
        return MaxLen;
    }
};
class Solution {
private:
    std::unordered_map<char, int> Dic = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        int Result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i+1 < s.size() && Dic[s[i+1]] > Dic[s[i]])
                Result -= Dic[s[i]];
            else
                Result += Dic[s[i]];
        }
        return Result;
    }
};
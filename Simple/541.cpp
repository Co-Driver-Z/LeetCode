class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        int Len = s.size();
        for (int i = 0; i < Len; i += 2 * k){
            reverse(s.begin() + i, s.begin() + min(i + k, Len));
        }
        return s;
    }
};
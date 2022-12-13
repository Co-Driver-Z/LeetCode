class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // 1) 获取数组长度
        int Len = (int)bits.size();
        // 2) While循环遍历
        int Pos = 0;
        bool Ans = false;
        while (Pos < Len) {
            if (Pos == Len-1 && bits[Pos] == 0) {
                Ans = true;
                break;
            }
            if (Pos+1 < Len && bits[Pos] == 1)
                Pos += 2;
            else
                Pos++;
        }
        return Ans;
    }
};
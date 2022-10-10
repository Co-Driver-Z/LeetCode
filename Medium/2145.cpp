class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int Result = 0;
        int Min = std::min(0, differences[0]);
        int Max = std::max(0, differences[0]);
        long long Temp = 0;
        for (int i = 0; i < differences.size(); ++i) {
            Temp = Temp + differences[i];
            if (Temp > Max) Max = Temp;
            if (Temp < Min) Min = Temp;
        }
        if ((lower - Min) + Max <= upper)
            return upper - ((lower - Min) + Max) + 1;
        return Result;
    }
};
class Solution {
public:
    int countEven(int num) {
        int Result = 0;
        if (num == 1000)
            num = 999;
        for (int i = 2; i <= num; ++i){
            int BPos = i / 100;
            int SPos = (i - BPos * 100) / 10;
            int GPos = i - BPos * 100 - SPos * 10;
            if ((GPos + SPos + BPos) % 2 == 0)
                ++Result;
        }
        return Result;
    }
};
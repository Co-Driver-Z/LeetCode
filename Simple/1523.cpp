class Solution {
public:
    int countOdds(int low, int high) {
        // // 1、初始化结果
        // int Result = 0;
        // // 2、for循环遍历
        // for (int i = low; i <= high; ++i) {
        //     if (i%2 != 0)
        //         ++Result;
        // }
        // return Result;

        // 1、如果两者相等，则判断该数是否为奇数
        if (high == low)
            return high%2 ? 1 : 0;
        // 2、应用公式计算（当两者至少有一个奇数时）
        if (high%2 || low%2)
            return (high - low) / 2 + 1;
        else         //（当两者都为偶数时）
            return (high - low) / 2;


        // // 前缀思想：0～high为 high+1/2个 / 0～low为low+1/2个； 
        // // 结果为：  (high+1)/2 - [(low-1)+1]/2
    }
};
class Solution {
public:
    // 分析:
    // 1、已知一个漂亮数组A, 且K(K!=0)、B为整数，则 K*A+B 也为漂亮数组
    // 2、1～N中，有奇数(N+1)/2个，有偶数N/2个

    // 1) 创建一个Hash表用于存储已经计算过的漂亮数组作为子解
    std::unordered_map<int, std::vector<int>> SubAns;

    // 2) 主函数
    vector<int> beautifulArray(int n) {
        // 1) 若子解计算过，则直接返回Hash表中的子解
        if (SubAns.find(n) != SubAns.end())
            return SubAns[n];
        // 2) 若子解没计算过，则开始计算
        std::vector<int> Ans(n, 0);
        int Pos = 0;
        if (n == 1) {
            Ans[0] = 1;
            SubAns[1] = Ans;
            return Ans;
        }
        // 2.1) 计算奇数部分
        for (const auto& Num : beautifulArray((n+1)/2)) {
            Ans[Pos++] = Num * 2 - 1;
        }
        // 2.2) 计算偶数部分
        for (const auto& Num : beautifulArray(n/2)) {
            Ans[Pos++] = Num * 2;
        }
        // 3) 返回结果
        SubAns[n] = Ans;
        return Ans;
    }
};
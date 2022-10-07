class Solution {
public:
    std::vector<long long> kthPalindrome(std::vector<int>& queries, int intLength) {
        // 1、制作回文数
        int PreLen = (intLength + 1) / 2;
        int PreMin = pow(10, PreLen-1);
        int PreMax = pow(10, PreLen) -1;
        auto Recover = [&](int Num) {
            std::string S = std::to_string(Num);
            // .1、intLength为偶数时
            if (intLength % 2 == 0) {
                for (int i = S.size()-1; i >= 0; --i)
                    S.push_back(S[i]);
            }
            // .2、intLength为奇数时
            else {
                for (int i = S.size()-2; i >= 0; --i)
                    S.push_back(S[i]);
            }
            return std::stoll(S);
        };
        // 2、返回结果
        std::vector<long long> Result;
        for (int i = 0; i < queries.size(); ++i) {
            if (queries[i] > PreMax - PreMin + 1)
                Result.push_back(-1);
            else
                Result.push_back(Recover(PreMin + queries[i] - 1));
        }
        return Result;
    }
};
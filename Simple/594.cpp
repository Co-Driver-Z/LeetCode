// Ref:
// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/longest-harmonious-subsequence/solution/zui-chang-he-xie-zi-xu-lie-by-leetcode-s-8cyr/
// 来源：力扣（LeetCode）
class Solution {
public:
    int findLHS(vector<int>& nums) {
        // 1、创建一个 hash 表，用于存储元素的个数
        int Result = 0;
        std::unordered_map<int, int> HashMap;
        for (const auto& num : nums) {
            HashMap[num]++;
        }
        // 2、遍历 hash 表，查看大于该元素的个数和该元素的个数，并对之前保存的临时最大个数做对比，取最大值
        for (const auto& [key, value] : HashMap) {
            if (HashMap.count(key+1))
                Result = std::max(Result, value + HashMap[key+1]);
        }
        return Result;

    }
};

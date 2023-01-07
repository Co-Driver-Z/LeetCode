class Solution {
public:
    // 思路: 从数组中寻找和为目标的两个元素
    // 1) 可采用使用 Hash Set 存储之前遍历的元素
    // 2) 每次遍历时判断 TargetNum - CurNUm 是否存在 Hash Set 中，如果存在则直接返回两个元素作为答案  
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1) 初始化 Hash Set
        std::unordered_set<int> Hash_Set;
        // 2) 进行一次For循环遍历
        for (int i = 0; i < nums.size(); ++i) {
            if (Hash_Set.find(target - nums[i]) != Hash_Set.end())
                return {target - nums[i], nums[i]};
            Hash_Set.insert(nums[i]);
        }
        return {};
    }
};
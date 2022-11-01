class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // 1、问题转化为求解数组中不为0且值不相等的元素的个数
        int Ans = (int)nums.size();
        std::unordered_map<int, int> Hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)  --Ans;
            else if (Hash.count(nums[i])) --Ans;
            else ++Hash[nums[i]];
        }
        return Ans;
    }
};
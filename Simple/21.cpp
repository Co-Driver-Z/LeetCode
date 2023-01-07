class Solution {
public:
    // 思路: 提前初始化答案，采用双指针，一次遍历nums，遇到奇数正序添加至答案，遇到偶数倒叙添加至答案（双指针添加）
    vector<int> exchange(vector<int>& nums) {
        // 0) 如果 nums 为空则返回空
        if (nums.size() == 0)
            return nums;
        // 1) 初始化答案，和双指针
        std::vector<int> Ans(nums.size(), 0);
        int LPos = 0; 
        int RPos = Ans.size() - 1;
        // 2) 一次 For 循环遍历 nums
        for (int i = 0; i < nums.size(); ++i) {
            // 偶数
            if (nums[i] % 2 == 0) {
                Ans[RPos] = nums[i];
                --RPos;
            }
            // 奇数
            else {
                Ans[LPos] = nums[i];
                ++LPos;
            }
        }
        return Ans;
    }
};
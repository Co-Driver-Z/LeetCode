class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int Result = 0;
        int LPos = 0;
        int Flag = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > right){
                Flag = -1;
                LPos = i + 1;
                continue;
            }
            if (nums[i] >= left && nums[i] <= right) {
                Flag = i;
            }
            if (Flag != -1) {
                Result += Flag - LPos + 1;
            }

        }
        return Result;
    }
};
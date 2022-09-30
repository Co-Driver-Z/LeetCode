// 1、哈希表方法
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int Result = 0;
        int Len = nums.size();
        std::unordered_map<int, int> OMap;
        for (int i = 0; i < Len; ++i) {
            Result += OMap.count(nums[i] + k) ? OMap[nums[i] + k] : 0;
            Result += OMap.count(nums[i] - k) ? OMap[nums[i] - k] : 0;
            ++OMap[nums[i]];
        }
        return Result;
    }
};


// 2、双指针暴力搜索法
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int Result = 0;
        for (int i = 0; i < nums.size(); ++i){
            for (int j = i+1; j < nums.size(); ++j){
                if (abs(nums[i] - nums[j]) == k){
                    Result++;
                }
            }
        } 
        return Result;
    }
};
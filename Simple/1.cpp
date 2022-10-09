class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> UnorderSet;
        std::vector<int> Result;
        for (int i = 0; i < nums.size(); ++i) {
            if (UnorderSet.count(target - nums[i]) == 1) {
        			Result.push_back(UnorderSet[target - nums[i]]);
					Result.push_back(i);  
                    return Result;
            }
            UnorderSet[nums[i]] = i;
		}
        return Result;
    }
};
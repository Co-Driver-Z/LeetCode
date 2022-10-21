class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 1、如果为1则直接返回第一行
        std::vector<vector<int>> Result;
        Result.push_back(std::vector<int> {1});
        if (numRows == 1) 
            return Result;
        // 2、如果大于1，则从第二行进行迭代计算
        for (int i = 0; i < numRows -1; ++i) {  
            std::vector<int> Temp; 
            Temp.push_back(1);          // 添加首位1
            for (int j = 0; j < Result.back().size() -1; ++j) {
                Temp.push_back(Result.back()[j] + Result.back()[j+1]);
            }
            Temp.push_back(1);          // 添加末位1
            Result.push_back(Temp); 
        }
        return Result;
    }
};
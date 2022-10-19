class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // 1、有向图表达信任关系:如果a信任b -> 则a指向b；建立入度和出度
        std::vector<int> InNums; std::vector<int> OutNums;
        InNums.resize(n+1); OutNums.resize(n+1);
        // 2、求解各个人的入度和出度
        for (const auto& V : trust) {
            ++InNums[V[1]]; ++OutNums[V[0]];
        }
        // 3、若一个人的入度为N，出度为0则该人为法官，返回其编号，否则返回-1
        for (int i = 1; i < n+1; ++i)
            if (InNums[i] == n-1 && OutNums[i] == 0)
                return i;
        return -1;
    }
};
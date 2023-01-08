class Solution {
public:
    // 思路: 机器人在矩形中的运动范围问题, 可采用广度优先搜索
    // 1) 从位置[0, 0]起开始搜索，遇到一个新的节点则判断是否可以达到，如果该节点已经访问过，则直接跳过（使用一个矩阵记录各个节点是否访问过）
    // 2) 设置一个int遍历，维护可访问节点的个数
    // 3) 编写一个函数用于求解一个数字的个位数之和
    int GetSum(int num) {
        int AnsTemp = 0;
        for (; num; num /= 10)
            AnsTemp += num % 10;
        return AnsTemp;
    }
    int movingCount(int m, int n, int k) {
        // 0) 如果 k == 0，则直接返回1
        if (k == 0)
            return 1;
        // 1) 设置一个m行n列的矩阵，用于标记节点是否访问过
        int Ans = 1;
        std::queue<std::pair<int, int>> Q;
        std::vector<std::vector<int>> visited(m, std::vector<int>(n));
        std::vector<std::pair<int, int>> Direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // 2) 从[0,0]开始广度优先搜索
        visited[0][0] = 1;
        Q.push(std::make_pair(0, 0));
        int QLen = 1;
        while (!Q.empty()) {
            QLen = Q.size();
            while (QLen > 0) {
                std::pair<int, int> CurPos = Q.front();
                Q.pop();
                for (const auto& Dir : Direction) {
                    int Newi = CurPos.first + Dir.first;
                    int Newj = CurPos.second + Dir.second;
                    int Temp = GetSum(Newi) + GetSum(Newj);
                    if (Newi >= 0 && Newi < m && Newj >= 0 && Newj < n && !visited[Newi][Newj] && Temp <= k) {
                        ++Ans;
                        visited[Newi][Newj] = 1;
                        Q.push(std::make_pair(Newi, Newj));
                    }  
                }
                --QLen;
            }
        }
        // 3) 返回答案
        return Ans;
    }
};
class Solution {
public:
    // 分析:
    // 对 king 国王的8个方向进行深度优先搜索，若碰到皇后则将皇后位置加入答案，如果碰到边界则返回。
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // 0) 构建地图: 2纬度的Map存储皇后的位置,Map[i][j]==1表示位置(i,j)处有皇后
        int Map[8][8] = {0};
        for (const auto& Pos : queens) {
            Map[Pos[0]][Pos[1]] = 1;
        }
        // 1) 构建方向数组
        std::vector<vector<int>> Dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        // 2) 分别从8个方向搜索
        std::vector<std::vector<int>> Ans;
        for (const auto& NowDir : Dir) {
            std::vector<int> Pos = king;
            Pos[0] += NowDir[0];
            Pos[1] += NowDir[1];
            while (Pos[0] >=0 && Pos[0] < 8 && Pos[1] >=0 && Pos[1] < 8) {
                if (Map[Pos[0]][Pos[1]] == 1) {
                    Ans.push_back({Pos[0], Pos[1]});
                    break;
                }
                Pos[0] += NowDir[0];
                Pos[1] += NowDir[1];
            }
        }
        // 3) 返回Ans
        return Ans;
    }
};
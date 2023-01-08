class Solution {
public:
    // 思路: 对于矩形中寻找目标单词问题，可采取"回溯"方法
    // 1) 创建一个 Check 函数，用于检测从i,j位置开始搜索word中第k位置后的子串是否在矩形中
    // 2) 对矩阵每一个元素进行 Cheak 函数检查，注意进入 Check 后要标记已经访问过的节点
    // 2) 如果最后都没找到，要使得访问过的节点恢复为未访问的（广度优先搜索）
    bool check(vector<vector<char>>& board, std::vector<std::vector<int>>& Direction, vector<vector<int>>& visitedboard, std::string& word, int i, int j, int k) {
        if (board[i][j] != word[k])
            return false;
        else if (k == word.size() - 1)
            return true;
        visitedboard[i][j] = 1;
        for (const auto& Dir : Direction) {
            int Newi = i + Dir[0];
            int Newj = j + Dir[1];
            if ( (Newi >= 0 && Newi < board.size()) && (Newj >= 0 && Newj < board[0].size()) && (!visitedboard[Newi][Newj]) ) {
                bool AnsTemp = check(board, Direction, visitedboard, word, Newi, Newj, k+1);
                if (AnsTemp)
                    return true;
            }
        }
        visitedboard[i][j] = 0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        // 1) 获取 board 的高度和宽度，并初始化 visitedboard 用于标记已经访问的节点
        int H = board.size(); 
        int W = board[0].size();
        std::vector<std::vector<int>> Direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::vector<std::vector<int>> visitedboard(H, std::vector<int>(W));
        bool Ans = false;
        // 2) For 循环遍历矩阵的每一个位置
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                Ans = check(board, Direction, visitedboard, word, i, j, 0);
                if (Ans)
                    return true;
            }
        }
        // 3) 搜索不到，返回 false
        return false;
    }
};
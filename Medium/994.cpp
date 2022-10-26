class Solution {
public:
    // 1、Time matrix, indicating the fastest decay time of oranges at this location
    int Time[10][10];
    // 2、Number of fresh oranges
    int FreshNums;
    // 3、A two-way queue that stores the current BFS search node
    std::queue<std::pair<int, int>> Q;
    // 4、Direction of BFS search
    int level[4] = {1, 0, -1, 0};
    int vertical[4] = {0, 1, 0, -1};
    // 5、Record the maximum number of times
    int MaxTime;
    
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        // 1、初始化相关参数
        memset(Time, -1, sizeof(Time));
        FreshNums = 0; MaxTime = 0;
        // 2、遍历一遍初始化FreshNums Q
        int Rows = (int)grid.size();
        int Columns = (int)grid[0].size();
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Columns; ++j) {
                if (grid[i][j] == 1)
                    ++FreshNums;
                else if (grid[i][j] == 2) {
                    Q.push(std::make_pair(i, j));
                    Time[i][j] = 0;
                }

            }
        }
        // 3、进行多源BFS搜索
        int Q_TempLen = Q.size();
        while (!Q.empty()) {
            while(Q_TempLen) {
                std::pair<int, int> TPoint = Q.front(); Q.pop();
                for (int i = 0; i < 4; ++i) {
                    int TX = TPoint.first  + vertical[i];
                    int TY = TPoint.second + level[i];
                    if (TX<0 || TX>=Rows || TY<0 || TY>=Columns || grid[TX][TY]!=1 || Time[TX][TY]>0) continue;
                    --FreshNums;
                    Time[TX][TY] = Time[TPoint.first][TPoint.second] + 1;
                    if (Time[TX][TY] > MaxTime)
                        MaxTime = Time[TX][TY];
                    Q.push(std::make_pair(TX, TY));
                }
                --Q_TempLen;
            }
            Q_TempLen = Q.size();
        }
        if (FreshNums > 0)
            return -1;
        else
            return MaxTime;

    }
};
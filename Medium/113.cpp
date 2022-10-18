// Ref: 
// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/QA2IGt/solution/ke-cheng-shun-xu-by-leetcode-solution-mq6d/

// // 1、深度优先搜索 DFS
// class Solution {
// private:
//     // 1、存储有向图
//     std::vector<vector<int>> Graph;
//     // 2、标记一个顶点是否被搜索过（0->无搜索 1->搜索中 2->搜索完成）
//     std::vector<int> State;
//     // 3、搜索完成的栈
//     std::vector<int> Stack;
//     // 4、标记是否有回环（有回环则无拓扑排序）
//     bool Flag = false;
// public:
//     void DFS(int P) {
//         // 1、标记该点搜索中
//         State[P] = 1;
//         // 2、搜索其相邻点（以该点为起点弧的终点）
//         for (const auto& U : Graph[P]) {
//             if (State[U] == 1) {
//                 Flag = true;
//                 return;
//             }
//             else if (State[U] == 0) {
//                 DFS(U);
//                 if (Flag == true) return;
//             }
                
//         }
//         // 3、标记已完成，返回
//         State[P] = 2;
//         Stack.push_back(P);
//         return;
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         // 1、完成建立有向图
//         Graph.resize(numCourses); State.resize(numCourses);
//         for (const auto& Edge : prerequisites) {
//             Graph[Edge[1]].push_back(Edge[0]);
//             State[Edge[1]] = 0;
//         }
//         // 2、进行深度优先搜索
//         for (int i = 0; i < numCourses && !Flag; ++i) {
//             if (State[i] == 0)
//                 DFS(i);
//         }
//         // 3、判断是否有回环
//         if (Flag)
//             return {};
//         // 4、无回环，对栈进行倒序排序返回
//         std::reverse(Stack.begin(), Stack.end());
//         return Stack;
//     }
// };
// 2、广度优先搜索 BFS
class Solution {
private:
    // 1、双vector表示有向图
    std::vector<vector<int>> Graph;
    // 2、表示各个点的入度  
    std::vector<int> InNums;       
    // 3、表示答案（栈）
    std::vector<int> Result;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1、创建有向图同事更新各个点的入度
        Graph.resize(numCourses); InNums.resize(numCourses);// vector初始化内容则为0
        for (const auto& Edge : prerequisites) {
            Graph[Edge[1]].push_back(Edge[0]);
            ++InNums[Edge[0]];
        }
        // 2、创建一个队列queue，首先将入度为0度推入队列
        std::queue<int> Q;
        for (int i = 0; i < numCourses; ++i) {
            if (InNums[i] == 0)
                Q.push(i);
        }
        // 3、当queue不为空时则：弹出第一个，将第一个加入答案，并开始减与其相关的点的入度，并判断是否为0是否添加入queue
        while (!Q.empty()) {
            int q = Q.front(); Q.pop(); Result.push_back(q);
            for (const auto& U : Graph[q]) {
                --InNums[U];
                if (InNums[U] == 0)
                    Q.push(U);
            }
        }
        // 4、当Result个数与numCourses一致时返回答案，否则有回环返回空
        if (Result.size() == numCourses)
            return Result;
        else
            return {};
    }
};

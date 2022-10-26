class Solution {
public:
    class Index2Dis {
    public:
        Index2Dis(int Index_, int Dis_):Index(Index_), Dis(Dis_){};
        int Index;
        int Dis;
    };
    bool operator()(Index2Dis& N1, Index2Dis& N2) {
        if (N1.Dis == N2.Dis)
            return N1.Index < N2.Index;
        else
            return N1.Dis < N2.Dis;
    }
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        std::vector<Index2Dis> V;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] == x || points[i][1] == y)
                V.push_back(Index2Dis(i, points[i][0]==x ? abs(points[i][1]-y) : abs(points[i][0]-x)));
        }
        if (V.size() > 0) {
            std::sort(V.begin(), V.end(), Solution());
            return V[0].Index;
        }
        else
            return -1;
        
    }
};
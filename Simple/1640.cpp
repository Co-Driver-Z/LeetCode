class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // 1、创建一个Hash表存储pieces中数组对应的数组索引
        std::unordered_map<int, int> Hash;
        for (int i = 0; i < pieces.size(); ++i) {
            for (int j = 0; j < pieces[i].size(); ++j) {
                Hash[pieces[i][j]] = i;
            }
        }
        // 2、遍历 arr
        int Pos = 0;
        while(Pos < arr.size()) {
            if (!Hash.count(arr[Pos]))
                return false;
            if (pieces[Hash[arr[Pos]]].size() == 1)
                ++Pos;
            else {
                if (Pos + pieces[Hash[arr[Pos]]].size() - 1 >= arr.size())
                    return false;
                for (int i = 0; i < pieces[Hash[arr[Pos]]].size(); ++i) {
                    if (arr[Pos + i] != pieces[Hash[arr[Pos]]][i])
                        return false;
                }
                Pos += pieces[Hash[arr[Pos]]].size();
            }
        }
        return true;
    }
};
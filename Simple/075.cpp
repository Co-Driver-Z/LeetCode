class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> Rank;
        for (int i = 0; i < arr2.size(); ++i) {
            Rank[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int x, int y){
            if (Rank.count(x))
                return Rank.count(y) ? Rank[x] < Rank[y] : true;
            else
                return Rank.count(y) ? false : x < y;
        });
        return arr1;
    }
};
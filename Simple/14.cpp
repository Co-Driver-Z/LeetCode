class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 方法一： Ref minmax_element 对string进行字典序排列
        // if (strs.empty())
        //     return "";
        // const auto Pos = minmax_element(strs.begin(), strs.end());
        // for (int i = 0; i < Pos.first->size(); ++i) {
        //     if (Pos.first->at(i) != Pos.second->at(i))
        //         return Pos.first->substr(0, i);
        // }
        // return *Pos.first;
        // 方法二：
        std::string S1 = strs.empty() ? "" : strs[0];
        for (auto S2 : strs) {
            while (S2.find(S1) != 0){
                S1 = S1.substr(0, S1.size() - 1);
            }
        }
        return S1;
    }
};
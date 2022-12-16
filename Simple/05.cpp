class Solution {
public:
    string replaceSpace(string s) {
        // 1) 第一次循环遍历s，记录空格的个数和相应的位置
        int SpaceNum = 0;
        std::unordered_map<int, int> Hash;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                ++SpaceNum;
                Hash[SpaceNum] = i;
            }    
        }
        // 2) 第二次循环遍历空格个数，对每个空格位置进行替换为"%20"，注意索引的变化 2 6 
        for (int i = 1; i <= SpaceNum; ++i) {
            std::string TempS = s;
            s = TempS.substr(0, Hash[i] + 2*(i-1));
            s = s + "%20";
            s = s + TempS.substr(Hash[i] + 2*(i-1) + 1);
        }
        return s;
    }
};
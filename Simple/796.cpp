class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        // 0、若长度不等则返回false
        if (s.size() != goal.size())
            return false;
        // 1、查找子串 + 剩余子串并判断
        std::string goal_ = goal;
        while (goal_.size() > 0) {
            if (s.find(goal_) == std::string::npos) {
                goal_ = goal_.substr(0, goal_.size()-1);
            }
            else {
                int Pos = s.find(goal_);
                if (s.substr(0, Pos) == goal.substr(goal_.size()))
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};
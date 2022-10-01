class Solution {
    std::vector<int> Years = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int GetDays (std::string& S) {
        int Result = 0;
        int Month = std::stoi(S.substr(0, 2));
        for (int i = 0; i < Month - 1; ++i)
            Result += Years[i];
        Result += std::stoi(S.substr(3));
        return Result;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int A1 = GetDays(arriveAlice), L1 = GetDays(leaveAlice);
        int A2 = GetDays(arriveBob),   L2 = GetDays(leaveBob);
        if (L1 >= A2 && L2 >= A1)
            return min(L1, L2) - max(A1, A2) + 1;
        else
            return 0;
    }
};
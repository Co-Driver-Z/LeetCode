class Solution {
public:
    // 从头部往后推导类似"跳台阶问题":
    // 0) TransNum 记录到当前位置可能的翻译方法个数
    // 1) if S[i-1] == '1'; || S[i-1] == '2' && S[i-1] <= '5';
    // 1）可以跳一步，也可以跳二步
    // TransNum[i] = TransNum[i-1] + TransNum[i-2];
    // 2) else
    // 2) 只能跳一步
    // TransNum[i] = TransNum[i-1];
    int translateNum(int num) {
        // 0) 如果num只有一位，则返回1
        if (num < 10)
            return 1;
        // 1) 初始化相关变量: TransNum
        std::string S = std::to_string(num); 
        int NumLen = (int)S.size();
        int TransNum[NumLen];
        memset(TransNum, 0, sizeof(TransNum));
        TransNum[0] = 1;
        if (S[0] == '1' || (S[0] == '2' && S[1] <= '5'))
            TransNum[1] = 2;
        else
            TransNum[1] = 1;
        // 2) 进行for循环更新: TransNum
        for (int i = 2; i < NumLen; ++i) {
            if (S[i-1] == '1' || (S[i-1] == '2' && S[i] <= '5'))
                TransNum[i] = TransNum[i-2] + TransNum[i-1];
            else
                TransNum[i] = TransNum[i-1];
        }
        // 3) 输出结果
        return TransNum[NumLen-1];
    }
};
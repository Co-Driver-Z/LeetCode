class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int Num1_S = 0;
        int Num1_X = 0;
        int Num2_S = 0;
        int Num2_X = 0;
        Num1_S = stoi(num1.substr(0, num1.find("+")));
        Num1_X = stoi(num1.substr(num1.find("+")+1, num1.find("i")));
        Num2_S = stoi(num2.substr(0, num2.find("+")));
        Num2_X = stoi(num2.substr(num2.find("+")+1, num2.find("i")));
        int S = Num1_S * Num2_S - Num1_X * Num2_X;
        int X = Num1_S * Num2_X + Num2_S * Num1_X;
        return to_string(S) + "+" + to_string(X) + "i";
    }
};
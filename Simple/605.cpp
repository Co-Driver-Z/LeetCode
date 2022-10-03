class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(0);
        int Pos = 0;
        while (Pos < flowerbed.size()-1 && n != 0) {
            if (flowerbed[Pos] == 0 && flowerbed[Pos+1] == 0) {
                --n;
                Pos += 2;
            }
            else if (flowerbed[Pos] == 0 && flowerbed[Pos+1] == 1) 
                Pos += 3;
            else if (flowerbed[Pos] == 1 && flowerbed[Pos+1] == 0) 
                Pos += 2;
        }   
        if (n == 0)
            return true;
        else
            return false;
    }
};
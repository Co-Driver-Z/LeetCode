class Solution {
public:
    int isPrefixOfWord(std::string sentence, std::string searchWord) {
        // 1、分割字符串
        int AirPos = 0;
        std::vector<std::string> Words;
        while ((AirPos = sentence.find(" ")) != std::string::npos) {
            Words.push_back(sentence.substr(0, AirPos));
            sentence = sentence.substr(AirPos + 1);
        }
        Words.push_back(sentence);
        // 2、循环进行匹配
        for (int i = 0; i < Words.size(); ++i) {
            int Pos = Words[i].find(searchWord);
            if (Pos == 0)
                return i + 1;
        }
        return -1;
    }
};
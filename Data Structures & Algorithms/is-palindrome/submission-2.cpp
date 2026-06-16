class Solution {
public:
    bool isPalindrome(string s) {

        string str{};
        for (auto ch: s) {
            if (not isalnum(ch)) {
                continue;
            }
            str += tolower(ch);
        }

        auto bIt = str.end() - 1;
        auto fIt = str.begin();
        
        while (fIt < bIt) {
            if (*fIt != *bIt) {
                return false;
            }
            bIt--;
            fIt++;
        }
        return true;
    }
};

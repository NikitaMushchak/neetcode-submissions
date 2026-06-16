class Solution {
public:
    bool isPalindrome(string s) {
        string normalString{};
        for (char ch: s) {
            if (not isalnum(ch)) {
                continue;
            }
            normalString += tolower(ch);
        }

        string reverseString{};
        for (auto it = normalString.rbegin(); it != normalString.rend(); ++it) {
            reverseString += *it;
        }
        return normalString == reverseString;
    }
};

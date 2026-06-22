class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        size_t size = s1.size();
        sort(s1.begin(), s1.end());

        for (int i = 0; i + size <= s2.size(); ++i) {
            string sub = s2.substr(i , size);
            sort(sub.begin(), sub.end());
            if (sub == s1) {
                return true;
            }
        }
        return false;
    }
};

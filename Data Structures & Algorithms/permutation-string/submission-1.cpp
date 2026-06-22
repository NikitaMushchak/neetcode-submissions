class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        size_t size = s1.size();
        sort(s1.begin(), s1.end());

        for (int i = 0; i < s2.size() - size + 1; ++i) {
            string sub{};
            int j = 0;
            while(j < size) {
                sub += s2[i + j];
                ++j;
            }
            sort(sub.begin(), sub.end());
            if (sub == s1) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int longest = 0;
        int l = 0;
        int maxF = 0;
        for (int r = 0; r < s.size(); ++r) {
            m[s[r]]++;
            maxF = max(maxF, m[s[r]]);

            while ((r - l + 1) - maxF > k) {
                m[s[l]]--;
                l++;
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};

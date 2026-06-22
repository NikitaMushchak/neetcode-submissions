class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> letters(s.begin(), s.end());
        int longest = 0;
        for (auto letter: letters) {
            int left = 0;
            int count = 0;
            for (int right = 0; right < s.size(); ++right) {
                if (s[right] == letter) {
                    count++;
                }

                while ((right - left + 1) - count > k) {
                    if (s[left] == letter) {
                        count--;
                    }
                    left++;
                }
                longest = max(longest, right - left + 1);
            }
        }
        return longest;
    }
};

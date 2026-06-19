class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // the second approach is to use left and right indecies
        //
        if(s.empty()) {
            return 0;
        } 
        int l = 0;
        unordered_set<char> chars;
        int longest = 0;

        for (int r = 0; r < s.size(); ++r) {
            while (chars.count(s[r])) {
                chars.erase(s[l]);
                l++;
            } 
            chars.insert(s[r]);
            
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};

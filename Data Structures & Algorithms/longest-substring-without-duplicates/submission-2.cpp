class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        // brute force is to get all posible 
        // substrings put them in the vector and return 
        // the largest one
        vector<set<char>> vecOfSet(s.size()); 
        for(size_t i = 0; i < s.size(); ++i) {
            auto & charSet = vecOfSet[i];
            size_t j = i;
            while (j < s.size()) {
                if (charSet.count(s[j])) {
                    break;
                } else {
                    charSet.emplace(s[j]);
                    j++;
                }
            }

        }

        int longest = 0;
        for (const auto & charSet: vecOfSet) {
            longest = max(longest, (int)charSet.size());
        }
        return longest;
    }
};

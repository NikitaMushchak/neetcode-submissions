class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26); // the vector where the index
        // from 0 to 25 is a letters from a to z
        int size = s1.size();
        if (size > s2.size()) {
            return false;
        }

        for (char ch: s1) {
            size_t idx = ch - 'a';
            freq[idx]++;
        }

        for (int i = 0; i + size <= s2.size(); ++i) {
            int j = 0;
            vector<int> subFreq(26);
            while (j < size) {
                char s2Char = s2[i + j];
                int idx = s2Char - 'a';
                subFreq[idx]++;
                j++;
            }
            if (freq == subFreq) {
                return true;
            }
        }
        return false;
    }
};

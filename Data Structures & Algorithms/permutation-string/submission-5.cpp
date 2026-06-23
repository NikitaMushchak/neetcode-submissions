class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26); // the vector where the index
        // from 0 to 25 is a letters from a to z
        int size = s1.size();
        if (size > s2.size()) {
            return false;
        }

        vector<int> subFreq(26);
        for (int i = 0; i < size; ++i) {
            size_t idx = s1[i] - 'a';
            freq[idx]++;
            size_t subIdx = s2[i] - 'a';
            subFreq[subIdx]++;
        }

        if (freq == subFreq) {
            return true;
        }
        // run through s2 and remove i - 1 and add i + size
        // char from subFreq, and compare Freq and subFreq
        for (int i = 1; i + size <= s2.size(); ++i) {
            // cout << "letter out: " << s2[i - 1] << ", letter add: " << s2[i + size] << endl;
            size_t bIdx = s2[i - 1] - 'a';
            subFreq[bIdx]--;
            size_t lIdx = s2[i + size - 1] - 'a';
            subFreq[lIdx]++;
            if (freq == subFreq) {
                return true;
            }
        }
        return false;
    }
};

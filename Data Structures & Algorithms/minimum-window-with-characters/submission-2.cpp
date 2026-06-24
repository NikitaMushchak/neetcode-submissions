class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        string out{};
        unordered_map<char, int> freqChar;
        unordered_map<char, int> window;
        for (char ch: t) {
            freqChar[ch]++;
        }

        // sliding window
        int l = 0;
        int need = freqChar.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int have = 0;
        for (int r = 0; r < s.size(); r++) {
            char ch = s[r];
            window[ch]++;
            if (freqChar.count(ch) && freqChar[ch] == window[ch]) {
                have++;
            }

            while (have == need) {
                if (resLen > (r - l + 1)) {
                    resLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if (freqChar.count(s[l]) && freqChar[s[l]] > window[s[l]]) {
                    have--;
                }
                l++;
            } 
        }


        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

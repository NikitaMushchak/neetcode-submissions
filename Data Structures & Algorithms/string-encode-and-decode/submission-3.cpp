class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (const auto str: strs) {
            res += to_string(str.size());
            res += '#';
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            size_t len = stoul(s.substr(i, j - i));
            // drop #
            j++;
            string dummy = s.substr(j, len);
            res.emplace_back(dummy);
            i = j + len;
        }
        return res;
    }
};

class Solution {
public:

    string encode(vector<string>& strs) {
        if (!strs.size()) {
            return {};
        }
        string res{"["};
        for (int i = 0; i < strs.size(); ++i) {
            size_t size = strs[i].size();
            if (i != strs.size() - 1 ) {
                res += to_string(size) + ',';
            } else {
                res += to_string(size);
            }
        }
        res += ']';

        for (const auto & str: strs) {
            res += str;
        }

        cout << "res: " << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) {
            return {};
        }
        vector<int> sizes;
        
        string size;
        auto it = s.begin();
        for (; it != s.end(); ++it) {
            //cout << "ch: " << *it << endl;
            char ch = *it;
            if (isdigit(ch)) {
                size += ch;
            }
            if (ch == ',' || ch == ']') {
                sizes.push_back(stoi(size));
                size.clear();
            }
            if (ch == ']') {
                break;
            }
        }
        // cout << "curent it: " << *++it << endl;
        ++it;
        vector<string> res;
        for (auto size: sizes) {
            // cout << "size: " << size << endl;
            string s;
            for (int i = 0; i < size; ++i) {
                if (it != s.end()) {
                    s += *it;
                    it++;
                }
            }
            res.push_back(s);
        }
        return res;
    }
};

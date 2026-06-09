class Solution {
public:
 string Signature(string str) {
    std::sort(str.begin(),str.end());
    return str;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> signatureAndVecs;
    vector<vector<string>> out;
    for (int i = 0; i < strs.size(); ++i) {
        string signature = Signature(strs[i]);

        signatureAndVecs[signature].push_back(strs[i]);
    }

    for (auto group: signatureAndVecs) {
        const vector<string> & groupStrs = group.second;
        out.emplace_back(groupStrs);
    }
    return out;
}
};

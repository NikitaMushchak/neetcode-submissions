class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        vector<int> res;
        for (const auto &num: nums) {
            auto it = frequency.find(num);
            if (it == frequency.end()) {
                frequency[num] = 1;
            }
            else {
                ++it->second;
            }
        }
        int maxFreq = 0;
        vector<pair<int, int>> freqAndVal;
        for (const auto & [num, freq]: frequency) {
            freqAndVal.push_back({freq, num});
        }
        sort(freqAndVal.begin(), freqAndVal.end(), 
             [](const pair<int, int>& lhv, const pair<int, int>& rhv)  {
                return lhv.first > rhv.first;
        });

        for (int i = 0; i < k; ++i) {
            res.push_back(freqAndVal[i].second);
        }
        return res;
    }
};

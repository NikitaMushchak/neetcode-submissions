class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // the main idea is to implement the 
        // frequency vector where size the size of the input vector
        // the index is the freq
        // e.g. [1,2,2,3,3,3], k = 2
        // freq vec: [0,1,2,3,0,0]
        
        // bucket sort algorithm
        vector<vector<int>> freq(nums.size() + 1);
        unordered_map<int, int> valAndFreq;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = valAndFreq.find(nums[i]);
            if (it == valAndFreq.end()) {
                valAndFreq[nums[i]] = 1;
            } else {
                ++it->second;
            }
        }

        for (const auto & [num, times]: valAndFreq) {
            freq[times].push_back(num);
        }

        vector<int> res;
        int i = 0;
        for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
            if (it->size() == 0) {
                continue;
            } 
            const vector<int> & vec = *it;
            for (auto val: vec) {
                if (i < k) {
                    res.push_back(val);
                    i++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

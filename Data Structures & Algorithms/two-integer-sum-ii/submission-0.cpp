class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;

        for (size_t i = 0; i < numbers.size(); ++i) {
            int complement = target - numbers[i];
            int idx = (int)i + 1;
            if (m.count(complement) && idx != m[complement]) {
                if (idx < m[complement]) { 
                    return {idx, m[complement]};
                }
                else { 
                    return {m[complement], idx};
                }
            } else {
                m[numbers[i]] = idx;
            }
        }
        return {};
    }
};

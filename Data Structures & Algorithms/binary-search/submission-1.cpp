class Solution {
public:
    int search(vector<int>& nums, int target) {
        // second aproach is std::map [number, index]

        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }

        if (m.count(target)) {
            return m[target];
        }
        return -1;
    }
};

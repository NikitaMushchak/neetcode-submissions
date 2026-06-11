class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix and suffix products approach

        vector<int> res(nums.size());
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        suffix[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >=0; --i) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            res[i] = suffix[i] * prefix[i];
        }
        return res;
    }
};

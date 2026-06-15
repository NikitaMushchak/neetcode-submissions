class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int maxLength = 1;
        int length = 1;
        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] - nums[i - 1] == 1) {
                length++;
                maxLength = max(maxLength, length);
            } else {
                length = 1;
            }
        }
        return maxLength;
    }
};

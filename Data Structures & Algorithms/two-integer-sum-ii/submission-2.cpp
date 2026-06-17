class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // use two pointers or indexes
        // numbers is sorted
        int lowIdx = 0;
        int highIdx = numbers.size() - 1;

        while (lowIdx < highIdx) {
            int sum = numbers[lowIdx] + numbers[highIdx];
            if (sum == target) {
                return {lowIdx + 1, highIdx + 1};
            }
            if (sum > target) {
                --highIdx;
            } else {
                ++lowIdx;
            }

        }
        return {};
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute force: we collect the all values to the subarrays on each 
        // sliding window step, sort the values to get the max value on each step

        vector<int> res;

        for (int i = 0; i + k <= nums.size(); i++) {
            vector<int> subArray;
            for (int j = 0; j < k; j++) {
                subArray.emplace_back(nums[j+i]);
            }
            sort(subArray.begin(), subArray.end(), greater<int>());
            res.emplace_back(subArray[0]);
        }
        return res;
    }
};

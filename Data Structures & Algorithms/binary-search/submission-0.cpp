class Solution {
public:
    int search(vector<int>& nums, int target) {
        // brute force go through the array and return 
        // the index of target O(N) complexity and O(1) space

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

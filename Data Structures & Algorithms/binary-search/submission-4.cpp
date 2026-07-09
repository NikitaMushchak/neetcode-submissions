class Solution {
public:
    int search(vector<int>& nums, int target) {
        // the final aproach is to use the left and rigth indices
        // [-1,0,3,5,9,12] t = 9
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }
        return -1;
    }
};

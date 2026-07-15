class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int idx = -1;
        while (l <= r) {
            // cout << "l: " << l << ", r: " << r << endl;
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                idx = mid;
                break;
            }
            if (nums[l] <= nums[mid]) { // left halv is sorted
               if (nums[l] <= target && nums[mid] > target) {
                    r = mid - 1;
               } else {
                l = mid + 1;
               }
            }                             //.     tar
            else { // right halv is sorted [mid, ..., r]
                if (nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return idx;
    }
};
// sorted [1,2,3,4,5,6]
// 
//  [3,4,5,6,1,2] t = 1
// mid = 0 + (5) / 2 = 2
// l = 3 r = 5
// mid = 3 + (2)/2 = 4
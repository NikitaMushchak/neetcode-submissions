class Solution {
public:
    int findMin(vector<int> &nums) {
        // all elements are unique
        // comp: O[logN], N- size of the array
        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                
                l = mid + 1;
                // cout << "l: " << l << endl;
            }
            else {
                r = mid;
            }
        }
        return nums[l];
    }
};
// nums = [1,2,3,4,5,6]
// rot 1 =[6,1,2,3,4,5]
// rot 2 =[5,6,1,2,3,4]
// rot 3 =[4,5,6,1,2,3]
// rot 4 =[3,4,5,6,1,2]

// l = 0 r = 5
//  n[l] > n[r]
// l = 3 r = 5
// n[3]= 6 n
// l = 3 + (5 - 3) / 2 = 4
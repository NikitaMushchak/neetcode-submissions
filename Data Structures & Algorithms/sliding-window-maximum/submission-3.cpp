class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute force: we collect the all values to the subarrays on each 
        // sliding window step, sort the values to get the max value on each step
        // algorithmic O[N^2 ln(N)]
        // Next approach to use sliding window 
        // let's use the window set
        if (nums.size() < k) {
            return {};
        }

        map<int, int, greater<int>> window;
        for (int i = 0; i < k; i++) {
            window[nums[i]]++;
        }
        vector<int> res;
        res.emplace_back(window.begin()->first);

        // erase nums[0] add nums[k]
        for (int i = 0; i + k < nums.size(); i++) {
            
            window[nums[i]]--;
            if (window[nums[i]] <= 0) {
                window.erase(nums[i]);
            }
            window[nums[i + k]]++;
            // cout << "erase: " << nums[i] << ", add: " << nums[i + k] << endl;
            res.emplace_back(window.begin()->first);
        }
        return res;
    }
};

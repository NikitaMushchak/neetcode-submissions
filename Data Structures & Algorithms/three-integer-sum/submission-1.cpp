class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // the nums is not sorted
        // return all posible sum of three equal to zero
        // space complexity is O(1)

        // #1 brute force 
        vector<vector<int>> out;
        for(int first = 0; first < nums.size(); ++first) {
            for (int second = first + 1; second < nums.size(); ++second) {
                for (int third = second + 1; third < nums.size(); ++third) {
                    if (nums[first] + nums[second] + nums[third] == 0) {
                        out.push_back({nums[first], nums[second], nums[third]});
                    }
                }
            }
        }

        for (auto & vec: out) {
            sort(vec.begin(), vec.end());
        }

        for (auto i = out.begin(); i != out.end(); ++i) {
            for (auto j = i + 1; j != out.end();) {
                if (*i == *j) {
                    j = out.erase(j);
                } else {
                    ++j;
                }
            }
        }
        return out;
    }
};

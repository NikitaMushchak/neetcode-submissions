class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // add the set to detect the multiple number apperance

        unordered_set<int> st;
        for (auto num: nums) {
            if (st.count(num)) {
                return num;
            } else {
                st.emplace(num);
            }
        }
        return -1;
    }
};

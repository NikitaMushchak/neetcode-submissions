class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longest = 0;
        int numSeq = 0;
        for (auto num: numSet) {
           numSeq = 1;
           longest = max(numSeq, longest);
           while (numSet.count(num + numSeq)) {
                numSeq++;
                longest = max(numSeq, longest);
           }
        }
        return longest;
    }
};

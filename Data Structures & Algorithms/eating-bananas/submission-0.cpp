class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int minVal = 1;
        int maxVal = INT_MIN;

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += piles[i];
            maxVal = max(maxVal, piles[i]);
        }
        int res = maxVal;

        while (minVal <= maxVal) {
            int mid = (maxVal + minVal) / 2;

            long long totalTime = 0;
            for (auto p: piles) {
                totalTime += ceil(static_cast<double>(p) / mid);
            }
            if (totalTime <= h) {
                res = mid;
                maxVal = mid - 1;
            }
            else {
                minVal = mid + 1;
            }
        }
        return res;
    }
};
// ban = [1,4,3,2], h = 9
// 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int buy = 0;
        int sell = 1;

        int maxP = 0;
        while (sell < prices.size()) {

            if (prices[sell] > prices[buy]) {
                maxP = max(maxP, prices[sell] - prices[buy]);
            } else {
                buy = sell; // we found cheaper price;
            }
            sell++;

        }
        return maxP;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // brute force we use aproach to calculate all prefits 
        // and return the best
        int maxProfit = 0;
        for (int buy = 0; buy < prices.size(); buy++) {
            for (int sell = buy + 1; sell < prices.size(); sell++) {
                maxProfit = max(prices[sell] - prices[buy], maxProfit);
            }
        }
        return maxProfit;
    }
};

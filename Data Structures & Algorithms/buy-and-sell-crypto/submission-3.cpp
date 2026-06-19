class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dynamic programing recalc profit and buy price dynamicaly
        int buyP = INT_MAX;
        int profit = 0;
        for (auto price: prices) {
            buyP = min(buyP, price);
            if (buyP < price) {
                profit = max(profit, price - buyP);
            }
        }
        return profit;
    }
};

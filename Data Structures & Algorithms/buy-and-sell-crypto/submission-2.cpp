class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, lowest_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            lowest_price = min(lowest_price, prices[i]);
            max_profit = max(max_profit, (prices[i] - lowest_price));
        }
        return max_profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, lowest_price = prices[0];
        for(int i=1;i<prices.size();i++){
            if(lowest_price > prices[i]){
                lowest_price = prices[i];
            }
            else{
                max_profit = max(max_profit, prices[i]-lowest_price);
            }
        }
        return max_profit;
    }
};

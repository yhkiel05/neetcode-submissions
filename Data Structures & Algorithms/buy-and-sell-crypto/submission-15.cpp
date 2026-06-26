class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int res = 0;
        for (int sell = 1; sell < prices.size(); sell++) {
            int profit = prices[sell] - prices[buy];
            if (profit < 0) {
                buy = sell;
            }
            res = max(profit, res);
        }
        return res;
    }
};

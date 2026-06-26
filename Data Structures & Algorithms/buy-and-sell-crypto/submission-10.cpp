class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int maxP = 0;
        for (int sell = 1; sell < prices.size(); sell++) {
            if (prices[buy] < prices[sell]) {
                int profit = prices[sell] - prices[buy];
                maxP = max(profit, maxP);
            } else {
                buy = sell;
            }
        }
        return maxP;
    }
};

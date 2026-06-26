class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int buy = 0;
        for (int sell = 1; sell < prices.size(); sell++) {
            if (prices[sell] > prices[buy]) {
                int profit = prices[sell] - prices[buy];
                maxP = max(maxP, profit);
            } else {
                buy = sell;
            }
        }
        return maxP;
    }
};

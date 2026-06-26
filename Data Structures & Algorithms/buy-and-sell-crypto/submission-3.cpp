class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int r = 1;
        int l = 0;
        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int temp = prices[r] - prices[l];
                if (temp > profit) {
                    profit = temp;
                }
            } else {
                l = r;
            }
            r++;
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) {
            return 0;
        }
        int maxProfit = 0;
        int curBuy = prices[0];
        for (int i = 0; i < n; i++) {
            if (curBuy > prices[i]) {
                curBuy = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - curBuy);
            }
        }
        return maxProfit;
    }
};

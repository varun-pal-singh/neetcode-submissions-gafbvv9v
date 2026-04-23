class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) return 0;
        int varun = 0, buyPrice = prices[0];
        for (int i = 0; i < n; i++) {
            if (buyPrice < prices[i]) {
                varun += prices[i] - buyPrice;
            }
            buyPrice = prices[i];
        }
        return varun;
    }
};
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit = 0
        curBuy = prices[0]
        for p in prices:
            if p < curBuy:
                curBuy = p
            profit = p - curBuy
            maxProfit = max(maxProfit, profit)
        return maxProfit
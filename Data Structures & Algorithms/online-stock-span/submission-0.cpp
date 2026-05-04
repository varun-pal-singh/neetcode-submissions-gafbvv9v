class StockSpanner {
private:
    std::stack<std::pair<int, int>> stk; // [price, cnt]
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt = 0;
        while (!stk.empty() && stk.top().first <= price) {
            cnt += stk.top().second + 1;
            stk.pop();
        }
        stk.push({price, cnt});
        return cnt + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
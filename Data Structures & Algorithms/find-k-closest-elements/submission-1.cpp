class Solution {
private:
    inline int closer(const int x, const int a) {
        return std::abs(x - a);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // closerVal, val
        priority_queue<pair<int, int>> maxHeap;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < n; i++) {
            int closerVal = closer(x, arr[i]);
            maxHeap.push({closerVal, arr[i]});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> res;
        while (!maxHeap.empty()) {
            auto p = maxHeap.top(); maxHeap.pop();
            res.push_back(p.second);
        }

        std::sort(res.begin(), res.end());

        return res;
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int size = stones.size();
        priority_queue<int> maxHeap;
        for (int i = 0; i < size; i++) {
            maxHeap.push(stones[i]);
        }
        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); maxHeap.pop();
            int x = maxHeap.top(); maxHeap.pop();
            if (x == y) {
                continue;
            }
            else {
                int diff = y - x;
                maxHeap.push(diff);
            }
        }

        return (maxHeap.empty()) ? 0 : maxHeap.top();
    }
};

class KthLargest {
   public:
    KthLargest(int k_, vector<int>& nums) {
        this->k = k_;
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]);
            if (minHeap.size() > k) minHeap.pop();
        }
        // while (minHeap.size() > k--) {
        //     minHeap.pop();
        // }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }

   private:
    int k = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

struct Compare {
    bool operator() (const int &a, const int &b) {
        return a > b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, Compare> minHeap;

        for (const int &num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.empty() ? -1 : minHeap.top();
    }
};

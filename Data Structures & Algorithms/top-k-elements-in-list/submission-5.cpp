class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // mp[num] = cnt;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, 
                        vector<pair<int, int>>,
                        std::greater<pair<int, int>>> minHeap;

        for (auto &p : mp) {
            minHeap.push({p.second, p.first});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};

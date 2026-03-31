class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int32_t, int32_t> freqs;
        for (const auto num: nums) {
            freqs[num] += 1;
        }

        priority_queue<pair<int32_t, int32_t>, vector<pair<int32_t, int32_t>>, greater<pair<int32_t, int32_t>>> heap;

        for (auto &entry: freqs) {
            heap.push({entry.second, entry.first});     // {freq, num}
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        while (!heap.empty()) {
            res.push_back(heap.top().second);   // num
            heap.pop();
        }

        return res;
    }
};

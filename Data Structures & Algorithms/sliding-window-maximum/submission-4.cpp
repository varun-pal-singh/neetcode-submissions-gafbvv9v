class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;
        int l = 0, r = 0;
        /*
        nums=   [1,3,1,2,0,5], k=3
        out:    [3,3,1,5]
        ex out: [3,3,2,5]
        */
        for (r = 0; r < n; r++) {
            while (l <= r && (r - l + 1) > k) {
                if (nums[l] == dq.front()) {
                    dq.pop_front();
                }
                l++;
            }
            while(!dq.empty() && dq.back() < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(nums[r]);
            if (r - l + 1 == k) res.push_back(dq.front());
        }
        return res;
    }
};

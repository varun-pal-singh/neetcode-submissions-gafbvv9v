class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (st.find(nums[i] - 1) == st.end()) {
                int cnt = 0;
                while (st.contains(nums[i] + cnt)) {
                    cnt ++;
                }
                mx = max(mx, cnt);
            }
        }
        
        return mx;
    }
};

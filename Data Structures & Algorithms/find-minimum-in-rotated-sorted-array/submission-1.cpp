class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int res = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[l] <= nums[mid]) {
                // sorted side
                res = std::min(res, nums[l]);
                l = mid + 1;
            }
            else {
                // sorted side
                res = std::min(res, nums[mid]);
                r = mid;
            }
        }

        return res != INT_MAX ? res : -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), res = -1;
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[l] <= nums[mid]) {
                // sorted side
                if (nums[l] <= target && target <= nums[mid]) {
                    // target is present in this section
                    res = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                // sorted side
                if (nums[mid] <= target && target <= nums[r]) {
                    // target is present in this section
                    res = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }

        return nums[res] == target ? res : -1;
    }
};

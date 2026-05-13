class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), idx = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[l] < nums[mid]) {
                // sorted side
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if (nums[l] > nums[mid]) {
                // sorted side
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            } 
            else {
                l++;
            }
        }
        return false;
    }
};
class Solution {
private:
    int n = 0;

    bool canSplit(vector<int> &nums, int k, int splitLimit) {
        int sum = 0;
        k--;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= splitLimit) {
                sum += nums[i];
            }
            else {
                // std::cout << "splited Sum: " << sum << "\n";
                k--;
                sum = nums[i];
            }
            if (nums[i] > splitLimit || k < 0)  return false;
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        int l = 1, r = accumulate(nums.begin(), nums.end(), 0);
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            // std::cout << "l: " << l << ", mid: " << mid << ", r: " << r << ", res: " << res << "\n";
            if (canSplit(nums, k, mid)) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};
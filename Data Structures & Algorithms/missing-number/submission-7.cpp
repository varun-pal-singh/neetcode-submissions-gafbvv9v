class Solution {
private:
    int n = 0;

    void cycleSort(vector<int> &nums) {
        int i = 0;
        while (i < n) {
            int correctIdx = nums[i];
            if (nums[i] < n && nums[correctIdx] != nums[i]) {
                swap(nums[correctIdx], nums[i]);
            }
            else {
                i++;
            }
        }
    }

public:
    int missingNumber(vector<int>& nums) {
        n = nums.size();
        // cycleSort(nums);

        int res = 0;

        for (int i = 0; i < n; i++) {
            res ^= nums[i];
            res ^= i;
        }

        res ^= n;

        return res;
    }
};

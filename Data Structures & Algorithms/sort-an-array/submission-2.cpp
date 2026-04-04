class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // selection sort
        for (int i = 0; i < n; i++) {
            int idx = i;
            // find min
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[idx]) {
                    idx = j;
                }
            }
            std::swap(nums[i], nums[idx]);
        }

        return nums;
    }
};
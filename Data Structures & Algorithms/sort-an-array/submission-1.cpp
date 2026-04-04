class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // bubble sort
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i] < nums[j]) {
                    std::swap(nums[i], nums[j]);
                }
            }
        }

        return nums;
    }
};
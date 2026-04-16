class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int total = nums[i] + nums[j];
            if (total < target) {
                i++;
            }
            else if (total > target) {
                j--;
            }
            else {
                return {i + 1, j + 1};
            }
        }
        return {-1, -1};
    }
};

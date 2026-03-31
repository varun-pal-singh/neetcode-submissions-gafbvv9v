class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1; 
        int i = 0;
        while (i <= r) {
            if (nums[i] == 0) {
                // put it in left;
                swap(nums[l++], nums[i]);
                i++;
            } else if (nums[i] == 2) {
                // put it in right;
                swap(nums[i], nums[r--]);
            } else {
                i++;
            }
        }
    }
};
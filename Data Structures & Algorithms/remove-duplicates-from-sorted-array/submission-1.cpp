class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int k = 1, uIdx = 0;
        int i = 1, j = n - 1;
        while (i <= j) {
            if (nums[i] != nums[uIdx]) {
                nums[uIdx + 1] = nums[i];
                uIdx++;
                k++;
            }
            i++;
        }
        return k;
    }
};
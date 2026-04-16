class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k = 1;
        int uIdx = 0, i = 1, j = n - 1;
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
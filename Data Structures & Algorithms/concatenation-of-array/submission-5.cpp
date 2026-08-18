class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> nums2(2 * size, 0);
        for (int i = 0; i < size; i++) {
            nums2[i] = nums[i];
            nums2[size + i] = nums[i];
        }
        return nums2;
    }
};
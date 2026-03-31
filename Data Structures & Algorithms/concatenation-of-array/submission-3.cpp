class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        if (size <= 0) return nums;
        vector<int> res(2 * size, -1);
        for (int32_t i = 0; i < size; i++) {
            res[i] = nums[i];
            res[i + size] = nums[i];
        } 
        return res;
    }
};
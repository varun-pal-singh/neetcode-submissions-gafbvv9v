class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t n = nums.size();
        if (n == 0) return nums;
        // vector<int32_t> res (2, -1);
        unordered_map<int32_t, int32_t> map;    // map[el] = i
        for (size_t i = 0; i < n; i++) {
            int32_t rem = target - nums[i];
            if (map.find(rem) != map.end()) {
                return {map[rem], i};
            }
            map[nums[i]] = i;
        } 
        return {-1, -1};
    }
};

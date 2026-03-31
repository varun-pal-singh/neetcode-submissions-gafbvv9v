class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hmap;
        for (int i = 0; i < n; i++) {
            int rem = target - nums[i];
            if (hmap.find(rem) != hmap.end()) {
                return {hmap[rem], i};
            }
            hmap.insert({nums[i], i});
        }
        return {};
    }
};

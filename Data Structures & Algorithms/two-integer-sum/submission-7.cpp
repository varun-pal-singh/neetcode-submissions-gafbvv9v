class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        std::map<int, int> hmap; // hmap[sum] = idx;
        for (int i = 0; i < size; i++) {
            int rem = target - nums[i];
            if (hmap.find(rem) != hmap.end()) {
                return {hmap[rem], i};
            }
            hmap[nums[i]] = i;
        } 
        return {-1, -1};
    }
};

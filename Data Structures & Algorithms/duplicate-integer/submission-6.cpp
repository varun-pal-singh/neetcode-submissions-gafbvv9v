class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> seen;
        for (int i = 0; i < size; i++) {
            if (seen.find(nums[i]) == seen.end()) {
                seen.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
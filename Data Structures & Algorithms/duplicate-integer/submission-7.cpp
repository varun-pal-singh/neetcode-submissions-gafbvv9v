class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> *seen = new unordered_set<int>;
        for (int i = 0; i < size; i++) {
            if (seen->find(nums[i]) != seen->end()) {
                return true;
            }
            seen->insert(nums[i]);
        }
        return false;
    }
};
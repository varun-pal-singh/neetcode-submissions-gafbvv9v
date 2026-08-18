class Solution {
private:
    void subsets(int i, int size, vector<int>& nums, vector<int>& subset,
                         vector<vector<int>>& allsubsets) {
        if (i == size) {
            allsubsets.push_back(subset);
            return;
        }

        // take i th
        subset.push_back(nums[i]);
        subsets(i + 1, size, nums, subset, allsubsets);
        subset.pop_back();

        // don't take i th
        subsets(i + 1, size, nums, subset, allsubsets);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int size = nums.size();
        vector<int> subset;
        vector<vector<int>> allsubsets;
        subsets(0, size, nums, subset, allsubsets);

        int xor_sum = 0;

        for (auto &subset : allsubsets) {
            int cur_xor = 0;
            for (int el : subset) {
                cur_xor ^= el;
            }
            xor_sum += cur_xor;
        }

        return xor_sum;
    }
};
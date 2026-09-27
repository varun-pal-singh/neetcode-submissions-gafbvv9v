class Solution {
private:
    int solve(std::vector<int> &nums, std::unordered_map<int, int> &umap, int i, int n) {
        if (i >= n) {
            return 0;
        }

        if (umap.find(i) != umap.end()) {
            return umap[i];
        }

        return umap[i] = std::max((nums[i] + solve(nums, umap, i + 2, n)), solve(nums, umap, i + 1, n));
    }

public:
    int rob(vector<int>& nums) {
        std::unordered_map<int, int> umap;  // umap[i] = sum;
        return solve(nums, umap, 0, nums.size());
    }
};

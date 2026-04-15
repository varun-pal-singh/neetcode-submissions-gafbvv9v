class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int diff = sum - k;
            res += prefix[diff];
            prefix[sum]+=1;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj0 = INT_MIN, maj1 = INT_MIN;
        int cnt0 = 0, cnt1 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == maj0) {
                cnt0++;
            } 
            else if (nums[i] == maj1) {
                cnt1++;
            } 
            else if (cnt0 == 0) {
                maj0 = nums[i];
                cnt0 = 1;
            } 
            else if (cnt1 == 0) {
                maj1 = nums[i];
                cnt1 = 1;
            }
            else {
                cnt0--;
                cnt1--;
            }
        }

        cnt0 = 0; cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maj0) {
                cnt0++;
            }
            else if (nums[i] == maj1) {
                cnt1++;
            }
        }

        vector<int> res;
        if (cnt0 > n / 3)   res.push_back(maj0);
        if (cnt1 > n / 3)   res.push_back(maj1);

        return res;
    }
};
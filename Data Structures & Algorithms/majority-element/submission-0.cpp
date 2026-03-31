class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt = 0, maj = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] == maj) {
                cnt ++;
            } else {
                cnt --;
            }
            if (cnt < 0) {
                cnt = 0;
                maj = nums[i];
            }
        }
        return cnt >= 0 ? maj : -1;
    }
};
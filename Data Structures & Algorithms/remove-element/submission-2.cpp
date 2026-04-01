class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int start = 0, last = n - 1;
        while (start <= last) {
            if (nums[start] == val) {
                // move it to the last
                std::swap(nums[start], nums[last]);
                last--;
            } else {
                start ++;
            }
        }

        // int i = 0;
        // for (i = 0; i < n; i++) {
        //     if (nums[i] == val) {
        //         break;
        //     }
        // }

        return start;
    }
};
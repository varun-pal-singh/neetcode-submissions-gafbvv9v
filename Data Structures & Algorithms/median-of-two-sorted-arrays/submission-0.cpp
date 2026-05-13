class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        vector<int> nums(n, 0);
        int i = 0, j = 0, idx = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                nums[idx] = nums1[i];
                i++;
            }
            else {
                nums[idx] = nums2[j];
                j++;
            }
            idx++;
        }

        while (i < n1)  nums[idx++] = nums1[i++];
        while (j < n2)  nums[idx++] = nums2[j++];

        i = n / 2;
        double median = nums[i];
        if ((n & 1) == 0) {
            median += nums[i - 1];
            median /= 2;
        }
        return median;
    }
};

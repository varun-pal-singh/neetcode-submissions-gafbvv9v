class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0, r = m;

        while (l <= r) {
            int mx = l + (r - l) / 2;
            int my = ((m + n + 1) / 2) - mx;

            // left half
            int x1 = (mx == 0) ? INT_MIN : nums1[mx - 1];
            int y1 = (my == 0) ? INT_MIN : nums2[my - 1];

            // right half
            int x2 = (mx == m) ? INT_MAX : nums1[mx];
            int y2 = (my == n) ? INT_MAX : nums2[my];


            if (x1 <= y2 && y1 <= x2) {
                double median = std::max(x1, y1);
                if (((m + n) & 1) == 0) {
                    median = (median + std::min(x2, y2)) / 2.0;
                }
                return median;
            }
            else if (x1 > y2) {
                r = mx - 1;
            }
            else {
                l = mx + 1;
            }
        }
        return -1;
    }
};

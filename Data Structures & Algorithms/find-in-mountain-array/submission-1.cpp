class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        size = mountainArr.length();
        if (size <= 2)  return -1;
        int peak = findPeak(mountainArr);
        std::cout << "peak: " << peak << "\n";
        int res1 = -1, res2 = -1;
        // checking left side first
        int l = 0, r = peak;
        while (l <= r) {
            int m = l + ((r- l) >> 1);
            int mid_val = mountainArr.get(m);
            if (mid_val == target) {
                return m;
            }
            else if (mid_val < target){
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        if (res1 != -1) return res1;

        // checking right side;
        l = peak; r = size - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            int mid_val = mountainArr.get(m);
            if (mid_val == target) {
                return m;
            }
            else if (mid_val > target){
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        return -1;
    }

private:
    int size = 0;
    int findPeak(MountainArray &arr) {
        int l = 0, r = size - 1;

        while (l < r) {
            int m = l + ((r - l) >> 1);

            if (arr.get(m) < arr.get(m + 1)) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
    }
};
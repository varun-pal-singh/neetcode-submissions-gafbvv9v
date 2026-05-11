class Solution {
public:
    int mySqrt(int x) {
        long l = 1, r = (long) x;
        while (l <= r) {
            long mid = l + (r - l) / 2;
            long sq = mid * mid;
            if (sq < (long) x) {
                l = mid + 1;
            }
            else if (sq > (long) x){
                r = mid - 1;
            } 
            else {
                return mid;
            }
        }

        return r;
    }
};
class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        n--;
        long long bit = 1, fill_bit = 1;
        while (n) {
            if ((x & bit) == 0) {
                if (n & fill_bit) {
                    res |= bit;
                }
                n >>= 1;
            }
            bit <<= 1;
        }

        return res;
    }
};
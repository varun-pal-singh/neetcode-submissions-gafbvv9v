class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 31; i >= 0; i--) {
            if (n & (1 << (31 - i))) {
                res += (1 << i);
            }
        }

        return res;
    }
};

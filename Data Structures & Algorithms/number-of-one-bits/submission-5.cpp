class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        // while (n) {
        //     n = n & (n - 1);
        //     cnt ++;
        // }

        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                cnt ++;
            }
        }
        return cnt;
    }
};

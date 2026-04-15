class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        // O(32)
        // for (int i = 0; i < 32; i++) {
        //     if (n & (1 << i)) {
        //         cnt ++;
        //     }
        // }

        // O(no of set bits)
        while (n) {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }
};

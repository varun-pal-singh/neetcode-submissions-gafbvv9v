class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        // for (int i = 0; i < 32; i++) {
        //     int bit_left  = (left & (1 << i))  ? 1 : 0;
        //     int bit_right = (right & (1 << i)) ? 1 : 0;
        //     if (bit_left & bit_right) {
        //         cout << i << "\n";
        //         res |= (1 << i);
        //     }
        // }

        int shift = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shift ++;
        }

        return left << shift;
    }
};
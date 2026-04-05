class Solution {
private:
    int getSetBitsCnt(int n) {
        int res = 0;
        while (n) {
            res++;
            n = n & (n - 1);
        }
        return res;
    }

public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(getSetBitsCnt(i));
        }
        return res;
    }
};

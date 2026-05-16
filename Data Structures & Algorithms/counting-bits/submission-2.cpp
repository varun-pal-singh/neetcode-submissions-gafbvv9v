class Solution {
private:
    int count(int n) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            cnt += (n & (1 << i)) ? 1 : 0;
        }
        return cnt;
    }

public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            res[i] = count(i);
        }

        return res;
    }
};

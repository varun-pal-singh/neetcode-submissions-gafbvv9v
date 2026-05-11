class Solution {
private:
    int n;
    bool canEatAll(vector<int> &piles, int h, int k) {
        int hours = 0;
        for (int i = 0; i < n; i++) {
            int cnt = std::ceil((double) piles[i] / k);
            hours += cnt;
            if (hours > h) {
                return false;
            }
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        n = piles.size();
        int res = -1;
        // int l = *min_element(piles.begin(), piles.end());
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        // std::cout << "l: " << l << ", r: " << r << "\n";
        while (l <= r) {
            int k = l + (r - l) / 2;
            if (canEatAll(piles, h, k)) {
                res = k;
                r = k - 1;
            }
            else {
                l = k + 1;
            }
        }
        return res;
    }
};

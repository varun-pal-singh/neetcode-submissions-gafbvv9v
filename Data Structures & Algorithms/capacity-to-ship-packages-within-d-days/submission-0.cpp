class Solution {
private:
    int n = 0;
    bool canShip(vector<int> &weights, int days, int limit) {
        int i = 0;
        int curDayWeight = 0;
        int cnt = 1;
        while (i < n) {
            if (curDayWeight + weights[i] <= limit) {
                curDayWeight += weights[i];
            }
            else {
                curDayWeight = weights[i];
                cnt ++;
            }
            if (weights[i] > limit || cnt > days)    return false;
            i++;
        }
        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        n = weights.size();
        int l = 1, r = accumulate(weights.begin(), weights.end(), 0);
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            // std::cout << "l: " << l << ", r: " << r << "\n";
            if (canShip(weights, days, mid)) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};
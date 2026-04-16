class Solution {
public:
    int reverse(int x) {
        int temp = abs(x);
        std::string strX = std::to_string(temp);
        std::reverse(strX.begin(), strX.end());
        
        long long res = stoll(strX);

        if (x < 0) {
            res *= -1;
        }

        if (res < -(1LL << 31) || res > ((1LL << 31) - 1)) {
            return 0;
        }

        return static_cast<int>(res);
    }
};

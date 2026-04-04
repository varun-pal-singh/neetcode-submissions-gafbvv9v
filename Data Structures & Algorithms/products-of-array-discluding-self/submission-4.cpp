class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), postfix(n, 1);
        int pre = 1, post = 1;

        // prefix & postfix fill
        for (int i = 0; i < n; i++) {
            pre  *= nums[i];
            post *= nums[n - 1 - i];

            prefix[i] = pre;
            postfix[n - 1 - i] = post;
        }

        // result
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            pre  = (i > 0)     ? prefix[i - 1] : 1;
            post = (i < n - 1) ? postfix[i + 1] : 1;
            res[i] = pre * post;
        }

        return res;
    }
};

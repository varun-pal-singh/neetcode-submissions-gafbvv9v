typedef long long ll;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int k = j + 1, l = n - 1;
                while (k < l) {
                    ll sum = nums[i] + nums[j];
                    sum += nums[k] + nums[l];
                    if (sum > ((ll) target)) {
                        l--;
                    }
                    else if (sum < ((ll) target)) {
                        k++;
                    }
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    }
                }
            }
        }

        return res;
    }
};
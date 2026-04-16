class Solution {
private:
    void print(vector<int> &nums, int i, int j) {
        std::for_each(nums.begin() + i, nums.begin() + j, [](const int &x){
            std::cout << x << " ";
        });
        std::cout << "\n";
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int mid = n - k;
        std::reverse(nums.begin(), nums.begin() + mid);
        // print(nums, 0, mid);
        std::reverse(nums.begin() + mid, nums.end());
        // print(nums, mid, n);
        std::reverse(nums.begin(), nums.end());
        // print(nums, 0, n);
    }
};
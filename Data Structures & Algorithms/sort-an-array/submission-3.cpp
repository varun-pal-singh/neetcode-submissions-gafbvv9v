class Solution {
private:
    void merge(vector<int> &nums, int l, int mid, int r) {
        int i = l, k = mid + 1;
        vector<int> temp;

        while (i <= mid && k <= r) {
            if (nums[i] < nums[k]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[k++]);
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i++]);
        }

        while (k <= r) {
            temp.push_back(nums[k++]);
        }


        // filling
        for (int i = l; i <= r; i++) {
            nums[i] = temp[i - l];
        }

    }

    void mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }


public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};
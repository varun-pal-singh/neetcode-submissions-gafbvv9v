class Solution {
private:
    void countingSort(vector<int>& nums) {
        int n = nums.size();
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int range = maxVal - minVal + 1;

        vector<int> count(range, 0);
        vector<int> output(n, 0);

        // frequency counting
        for (int i = 0; i < n; i++) {
            count[nums[i] - minVal] ++;
        }

        // prefix sum for count freq to index finding
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

//      nums  = [1,3,2,3,2]
//      count = [1,1,5,6,6]

        for (int i = n - 1; i >= 0; i--) {
            int idx = nums[i] - minVal;
            output[count[idx] - 1] = nums[i];
            count[idx]--;
        }
//      output = [1,2,2,3,3]

        nums = output;
    }

    void print(vector<int> &nums) {
        int n = nums.size();
        std::cout << "[ ";
        for (int i = 0; i < n; i++) {
            std::cout << nums[i] << ", ";
        }
        std::cout << "]" <<  std::endl;
    }

public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        if (n <= 0) return 0;
        // std::sort(people.begin(), people.end());
        countingSort(people);
        // print(people);
        int l = 0, r = n - 1;
        int boats = 0;
        while (l <= r) {
            int sum = people[l] + people[r];
            if (sum <= limit) {
                l++;
            }
            r--;
            boats++;
        }
        return boats;
    }
};
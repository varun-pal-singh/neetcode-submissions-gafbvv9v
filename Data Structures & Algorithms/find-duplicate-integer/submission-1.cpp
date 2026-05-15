class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)  return -1; 
        unordered_set<int> seen;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (seen.find(*it) != seen.end()) {
                return *it;
            }
            seen.insert(*it);
        }

        return -1;
    }
};

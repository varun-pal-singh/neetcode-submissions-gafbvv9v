class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, mx = 0;
        unordered_set<char> seen;
        for (int r = 0; r < n; r++) {
            while (l < r && seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);

            mx = max(mx, r - l + 1);
        }

        return mx;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int l = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                l = max(l, mp[s[i]] + 1);
            }
            mx = max(mx, i - l + 1);
            mp[s[i]] = i;
        }
        return mx;
    }
};

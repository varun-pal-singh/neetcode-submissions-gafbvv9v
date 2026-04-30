class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;
        int mx = 0;
        int l = 0, maxf = 0;
        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);

            while ((r - l + 1) - maxf > k) {
                mp[s[l]]--;
                l++;
            }

            mx = max(mx, r - l + 1);
        }

        return mx;
    }
};

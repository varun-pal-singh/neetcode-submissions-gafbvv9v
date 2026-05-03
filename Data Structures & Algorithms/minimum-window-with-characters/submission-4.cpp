class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.length();
        if (n < t.length()) return "";
        unordered_map<char, int> mp;
        for_each(t.begin(), t.end(), [&mp](char ch) { mp[ch]++; });

        int cnt = mp.size(), mn = INT_MAX, lastPos = -1;
        // "cabwefgewcwaefgcf"
        // "cae"

        int l = 0, r = 0;
        int res[2] = {-1, -1};

        for (r = 0; r < n; r++) {
            char cr = s[r];
            if (mp.find(cr) != mp.end()) {
                mp[cr]--;
                if (mp[cr] == 0) cnt--;
            }

            while (l <= r && (cnt <= 0 || mp.find(s[l]) == mp.end())) {
                if (mp.find(s[l]) != mp.end()) {
                    // s[l] exists in map and its a valid window
                    mp[s[l]]++;
                    if (mp[s[l]] == 1) cnt++;
                    if (mn > r - l + 1) {
                        res[0] = l;
                        res[1] = r;
                        mn = r - l + 1;
                    }
                }
                l++;
            }
        }
        int size = res[1] - res[0] + 1;
        return (mn != INT_MAX) ? s.substr(res[0], size) : "";
    }
};

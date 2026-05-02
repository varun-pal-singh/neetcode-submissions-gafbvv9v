class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        // string s1 = "abc";
        unordered_map<char, int> mp1;
        for_each(s1.begin(), s1.end(), [&mp1](char c) { mp1[c]++; });

        int l = 0, cnt = mp1.size();
        for (int r = 0; r < n2; r++) {
            while (l <= r && (r - l + 1) > n1) {
                if (mp1.find(s2[l]) != mp1.end()) {
                    mp1[s2[l]]++;
                    if (mp1[s2[l]] == 1) cnt++;
                }
                l++;
            }

            char c = s2[r];
            if (mp1.find(c) != mp1.end()) {
                mp1[c]--;
                if (mp1[c] == 0) {
                    cnt--;
                }
            }
            if (cnt == 0) {
                return true;
            }
        }

        return false;
    }
};

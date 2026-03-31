class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if (n != m) return false;
        int umap[26] = {0};
        for (int i = 0; i < n; i++) {
            umap[s[i] - 'a'] += 1;
            umap[t[i] - 'a'] -= 1;
        }

        for (int val: umap) {
            if (val) return false;
        }
        return true;
    }
};

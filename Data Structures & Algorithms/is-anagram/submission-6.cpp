class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        int n = s.length(), m = t.length();
        if (n != m) return false;
        for (int i = 0; i < n; i++) {
            umap[s[i]] += 1;
        }
        for (int i = 0; i < n; i++) {
            if (umap.find(t[i]) == umap.end())
                return false;
            umap[t[i]] -= 1;
            if (umap[t[i]] == 0) {
                umap.erase(t[i]);
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        // using keyType = std::array<int, 26>;
        unordered_map<std::string, std::vector<std::string>> umap;
        for (int i = 0; i < n; i++) {
            int count[26] = {0};
            for (char ch: strs[i]) {
                count[ch - 'a'] += 1;
            }
            std::string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }
            umap[key].push_back(strs[i]);
        }

        vector<vector<std::string>> res;
        for (const auto &pair: umap) {
            res.push_back(pair.second);
        }
        return res;
    }
};

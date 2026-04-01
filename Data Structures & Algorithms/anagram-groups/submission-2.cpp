class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mmap;
        for (int i = 0; i < n; i++) {
            string key = strs[i];
            std::sort(key.begin(), key.end());
            if (mmap.find(key) == mmap.end()) {
                mmap[key] = {strs[i]};
            } else {
                mmap[key].push_back(strs[i]);
            }
        }

        vector<vector<string>> res;
        for (auto &p: mmap) {
            res.push_back(p.second);
        }

        return res;
    }
};

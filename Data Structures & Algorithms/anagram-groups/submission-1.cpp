#include <array>

struct Hash {
    size_t operator() (const std::array<int32_t, 26> &arr) const {
        size_t h = 0;
        for (const int32_t x : arr) {
            h = h * 31 + x; // polynomial hash
        }
        return h;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        size_t n = strs.size();
        vector<vector<string>> res;
        if (n == 0) return res;

        unordered_map<std::array<int32_t, 26>, vector<string>, Hash> mapp;
        for (const string &str : strs) {
            std::array<int32_t, 26> key = {0};
            for (const char &c : str) {
                key[c - 'a'] += 1;
            }
            mapp[key].push_back(str);
        }

        for (const auto &p : mapp) {
            res.push_back(p.second);
        }
        return res;
    }
};

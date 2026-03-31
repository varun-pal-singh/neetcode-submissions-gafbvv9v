class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n <= 0) return "";
        std::sort(strs.begin(), strs.end());

        int n1 = strs[0].length();
        for (int i = 0; i < n1; i++) {
            if (strs[0][i] != strs.back()[i]) {
                return strs[0].substr(0, i);
            }
        }

        return strs[0];
    }
};
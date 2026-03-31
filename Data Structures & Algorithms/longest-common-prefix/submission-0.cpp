class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string res = "";
        int i = 0, n = strs.size(), m = strs[0].size();
        while (i < m && strs[0][i] == strs[n-1][i]) {
            res += strs[0][i];
            i++;
        }
        return res;
    }
};
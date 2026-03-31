class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), m = 0;
        std::string res = "";
        int i, midx = -1;
        for (i = 0; i < n; i++) {
            if (m <= strs[i].size()) {
                m = strs[i].size();
                midx = i;
            }
        }
        bool flag;
        for (i = 0; i < m; i++) {
            char ch = strs[0][i];
            flag = false;
            for (int j = 0; j < n; j++) {
                if (strs[j][i] != ch){
                    flag = true;
                }
            }
            if (flag) {
                break;
            }
        }
        res = strs[midx].substr(0, i);
        return res;
    }
};
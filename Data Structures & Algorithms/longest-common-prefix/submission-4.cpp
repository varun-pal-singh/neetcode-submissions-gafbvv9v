class Solution {
public:
    // static bool cmp(string a, string b) {
    //     return a.length() < b.length();
    // }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        std::sort(strs.begin(), strs.end(), [] (string s1, string s2) {
            return s1.length() < s2.length();
        });

        std::string s1 = strs[0], s2 = strs[n - 1];
        int n1 = s1.length();
        int i;
        for (i = 0; i < n1; i++) {
            if (s1[i] != s2[i]) {
                break;
            }
        }
        string res = (i > 0) ? s1.substr(0, i) : "";
        int n2 = res.length();
        for (i = 0; i < n2; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i] != strs[j][i]) {
                    res = res.substr(0, i);
                    break;
                }
            }
        }

        return res;
    }
};
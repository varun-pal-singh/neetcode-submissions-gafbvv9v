class Solution {
private:
    char hashChar = '!';
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        if (n <= 0) return "";
        std::string res = "";
        for (int i = 0; i < n; i++) {
            int tSize = strs[i].length();
            res += to_string(tSize) + hashChar + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> res;
        int i = 0;
        while (i < n) {
            int j = i;
            while (s[j] != hashChar) {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + len;
            res.push_back(s.substr(i, len));
            i = j;
        }
        return res;
    }
};

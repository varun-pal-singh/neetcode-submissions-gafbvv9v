class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        int i = 0, j = 0;

        std::string res = "";

        while (i < n1 || j < n2) {
            if (i < n1) {
                res += word1[i];
                i++;
            }

            if (j < n2) {
                res += word2[j];
                j++;
            }
        }

        return res;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n == 0) return false;
        int i = 0, j = n - 1;
        while (i < j) {
            if (!isalnum(s[i]) || s[i] == ' ') {
                i++;
                continue;
            }
            else if (!isalnum(s[j]) || s[i] == ' ') {
                j--;
                continue;
            }
            else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

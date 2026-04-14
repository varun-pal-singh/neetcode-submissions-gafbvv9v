class Solution {
private:
    bool isalnum(char c) {
        return (
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9')
        );
    }

    char tolower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }
        return c;
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int n = s.length();
        if (n <= 2) return true;
        
        int l = 0, r = n - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                return (
                    isPalindrome(s.substr(0, l) + s.substr(l + 1)) ||
                    isPalindrome(s.substr(0, r) + s.substr(r + 1))
                );
            }
            l++;
            r--;
        }

        return true;
    }
};
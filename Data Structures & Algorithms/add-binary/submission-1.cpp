class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length(), n2 = b.length();
        int i = n1 - 1, j = n2 - 1;
        char carry = '0', t = '0';
        string res = "";

        while (i >= 0 && j >= 0) {
            char x = a[i], y = b[j];
            t = '0';
            if (x == '0' && y == '0') {
                t = (carry == '1') ? '1' : '0';
                carry = '0';
            } else if ((x == '0' && y == '1') || (x == '1' && y == '0')){
                if (carry == '1') {
                    t = '0';
                    carry = '1';
                } else {
                    t = '1';
                    carry = '0';
                }
            } else if (x == '1' && y == '1') {
                t = (carry == '1') ? '1' : '0';
                carry = '1';
            }
            res += t;
            i--;
            j--;
        }

        // cout << "res 1st loop: " << res << " carry: " << carry << "\n";

        while (i >= 0) {
            if (a[i] == '1') {
                if (carry == '1') {
                    t = '0';
                    carry = '1';
                } else {
                    t = '1';
                    carry = '0';
                }
            } else {
                if (carry == '1') {
                    t = '1';
                    carry = '0';
                } else {
                    t = '0';
                    carry = '0';
                }
            }
            res += t;
            i--;
        }

        // cout << "res 2nd loop: " << res << " carry: " << carry << "\n";

        while (j >= 0) {
            if (b[j] == '1') {
                if (carry == '1') {
                    t = '0';
                    carry = '1';
                } else {
                    t = '1';
                    carry = '0';
                }
            } else {
                if (carry == '1') {
                    t = '1';
                    carry = '0';
                } else {
                    t = '0';
                    carry = '0';
                }
            }
            res += t;
            j--;
        }

        // cout << "res 3rd loop: " << res << " carry: " << carry << "\n";

        if (carry == '1') {
            res += '1';
        }

        // std::cout << "res before reverse: " << res << "carry: " << carry << "\n";

        reverse(res.begin(), res.end());

        return res;
    }
};
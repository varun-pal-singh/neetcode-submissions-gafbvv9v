class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length(), n2 = b.length();
        vector<char> res;
        int carry = 0;

        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 || j >= 0 || carry) {
            int val1 = 0, val2 = 0;
            if (i >= 0) {
                val1 = (a[i] == '1') ? 1 : 0;
            }
            if (j >= 0) {
                val2 = (b[j] == '1') ? 1 : 0;
            }

            int val = val1 + val2 + carry;
            carry = val / 2;
            val = val % 2;
            char ch = (val == 1) ? '1' : '0';
            res.emplace_back(ch);
            i--;
            j--;
        }

        // if (res[res.size() - 1] == '0') res.pop_back();
        
        reverse(res.begin(), res.end());

        string str(res.begin(), res.end());
        // cout << str << endl;
        return str;
    }
};
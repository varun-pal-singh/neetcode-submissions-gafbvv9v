class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> res;

        while (columnNumber) {
            columnNumber--;
            int last_char_idx = columnNumber % 26;
            printf("col_no: %d, last_char_idx: %d\n", columnNumber, last_char_idx);

            char lastChar = 'A' + last_char_idx;

            res.emplace_back(lastChar);
            columnNumber /= 26;
        }

        std::reverse(res.begin(), res.end());

        std::string str(res.begin(), res.end());
        return str;
    }
};


// 1000 -> 38 full division and remainder 12
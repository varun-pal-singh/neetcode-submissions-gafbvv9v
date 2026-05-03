template <typename T>
std::ostream& operator<<(std::ostream& os, std::stack<T> ds) {
    while (!ds.empty()) {
        os << ds.top() << " ";
        ds.pop();
    }
    os << "\n";
    return os;
};

class Solution {
   public:
    bool isValid(string s) {
        int n = s.length();
        unordered_map<char, char> mp = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        std::stack<char> stk;
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    stk.push(s[i]);
                    break;
                case ')':
                case '}':
                case ']':
                    if (!stk.empty() && mp[stk.top()] == s[i]) {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
            }
        }
        // std::cout << stk;
        return stk.empty();
    }
};

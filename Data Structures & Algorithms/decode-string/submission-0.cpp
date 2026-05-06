class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        string curr = "";
        int num = 0;
        stack<string> strStk;
        stack<int>    numStk;
        
        for (const char &ch : s) {
            if (std::isdigit(ch)) {
                num = (num * 10) + (ch - '0');
            }
            else if (ch == '[') {
                numStk.push(num);
                strStk.push(curr);
                curr = "";
                num = 0;
            }
            else if (ch == ']') {
                int repeat = numStk.top(); numStk.pop();
                string temp = curr;
                curr = strStk.top(); strStk.pop();
                while (repeat-->0) {
                    curr += temp;
                } 
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> stk;
        string cur;
        stringstream ss(path);
        while (getline(ss, cur, '/')) {
            if (cur.empty())    continue;
            else if (cur == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            }
            else if (cur != ".") {
                stk.push(cur);
            }
        }

        vector<string> vec;
        while (!stk.empty()) {
            vec.push_back(stk.top());
            stk.pop();
        }
        string res = "/";
        for (auto it = vec.rbegin(); it != vec.rend(); it++) {
            res += *it;
            if (it + 1 != vec.rend()) res += "/";
        }
        
        return res;
    }
};
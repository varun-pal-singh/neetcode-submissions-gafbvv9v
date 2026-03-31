class Solution {
public:
    bool isAnagram(string s, string t) {
        int size = s.length(), sizeT = t.length();

        if (size != sizeT)  return false;

        vector<int> seen(26, 0);

        for (int i = 0; i < size; i++) {
            seen[s[i] - 'a'] += 1;
            seen[t[i] - 'a'] -= 1;
        }

        for (int i = 0; i < 26; i++) {
            if (seen[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

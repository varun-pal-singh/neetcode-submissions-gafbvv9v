class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.length(), t_size = t.length();
        if (s_size != t_size) {
            return false;
        }

        int arr[26] = {0};

        // for (int i = 0; i < 26; i++) {
        //     std::cout << "arr[" << i << "] : " << arr[i] << ", " ;
        // }

        for (int i = 0; i < s_size; i++) {
            arr[s[i] - 'a'] += 1;
            arr[t[i] - 'a'] -= 1;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) 
                return false;
        }

        return true;
    }
};

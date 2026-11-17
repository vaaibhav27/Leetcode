
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0) {
                string sub = s.substr(0, len);
                string temp = "";

                while (temp.length() < n) {
                    temp += sub;
                }

                if (temp == s) {
                    return true;
                }
            }
        }

        return false;
    }
};

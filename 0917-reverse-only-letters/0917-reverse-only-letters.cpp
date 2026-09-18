class Solution {
public:
    bool isLetter(char ch) {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z');
    }

    string reverseOnlyLetters(string s) {

        int l = 0;
        int r = s.size() - 1;

        while (l < r) {

            if (!isLetter(s[l])) {
                l++;
            }

            else if (!isLetter(s[r])) {
                r--;
            }

            else {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }

        return s;
    }
};
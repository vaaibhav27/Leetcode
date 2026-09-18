class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for (string word : words) {

            int l = 0;
            int r = word.size() - 1;

            bool palindrome = true;

            while (l < r) {

                if (word[l] != word[r]) {
                    palindrome = false;
                    break;
                }

                l++;
                r--;
            }

            if (palindrome) {
                return word;
            }
        }

        return "";
    }
};
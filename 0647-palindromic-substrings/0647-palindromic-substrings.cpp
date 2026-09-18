class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                int left = i;
                int right = j;

                bool palindrome = true;

                while (left < right) {

                    if (s[left] != s[right]) {
                        palindrome = false;
                        break;
                    }

                    left++;
                    right--;
                }

                if (palindrome) {
                    count++;
                }
            }
        }

        return count;
    }
};
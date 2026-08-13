class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while(l <= r) {

            while(l < r && 
                  !((s[l] >= 'a' && s[l] <= 'z') ||
                    (s[l] >= 'A' && s[l] <= 'Z') ||
                    (s[l] >= '0' && s[l] <= '9'))) {
                l++;
            }

            while(l < r && 
                  !((s[r] >= 'a' && s[r] <= 'z') ||
                    (s[r] >= 'A' && s[r] <= 'Z') ||
                    (s[r] >= '0' && s[r] <= '9'))) {
                r--;
            }

            char left = s[l];
            char right = s[r];

            if(left >= 'A' && left <= 'Z')
                left = left + 32;

            if(right >= 'A' && right <= 'Z')
                right = right + 32;

            if(left != right)
                return false;

            l++;
            r--;
        }

        return true;
    }
};
class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        
        while(l < r) {
            if((s[l] != 'A' && s[l] != 'E' && s[l] != 'I' && s[l] != 'O' && s[l] != 'U' &&
             s[l] != 'a' && s[l] != 'e' && s[l] != 'i' && s[l] != 'o' && s[l] != 'u') 
            ) {
                l++;
            }
            if((s[r] != 'A' && s[r] != 'E' && s[r] != 'I' && s[r] != 'O' && s[r] != 'U' &&
             s[r] != 'a' && s[r] != 'e' && s[r] != 'i' && s[r] != 'o' && s[r] != 'u')) {
                r--;
            }
            if((s[l] == 'A' || s[l] == 'E' || s[l] == 'I' || s[l] == 'O' || s[l] == 'U' ||
             s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') &&
             (s[r] == 'A' || s[r] == 'E' || s[r] == 'I' || s[r] == 'O' || s[r] == 'U' ||
             s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u')) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
            
        }
        return s;
    }
};
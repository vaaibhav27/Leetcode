class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int maxi = 0;
        int l = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if((s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
             s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')) {
                cnt++;
            }
            while(i-l+1 > k) {
                if((s[l] == 'A' || s[l] == 'E' || s[l] == 'I' || s[l] == 'O' || s[l] == 'U' ||
             s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')) {
                    cnt--;
                }
                l++;
            }
            maxi = max(cnt, maxi);
        }
        return maxi;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        int hash[256];
        for(int i = 0; i<256; i++) hash[i] = -1;

        int l = 0, r = 0;
        while(r<n) {
            if(hash[s[r]] != -1 && l <= hash[s[r]]) l = hash[s[r]] + 1;

            hash[s[r]] = r;
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};
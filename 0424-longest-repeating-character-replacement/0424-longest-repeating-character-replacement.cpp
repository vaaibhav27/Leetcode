class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxlen = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        int maxfreq = 0;
        int chance = 0;
        while(r < n) {
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);
            int chance = r-l+1 - maxfreq;
            
            while(chance > k) {
                mp[s[l]]--;
                l++;
                chance = r-l+1 - maxfreq;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};
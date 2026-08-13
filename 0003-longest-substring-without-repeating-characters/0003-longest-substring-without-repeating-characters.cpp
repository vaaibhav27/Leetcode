class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        int cnt = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            mp[s[r]]++;
            while(mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            }
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};
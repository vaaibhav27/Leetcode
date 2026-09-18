class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        int cnt = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
            while(mp[s[i]] > 1) {
                mp[s[l]]--;
                l++;
            }
            maxi = max(maxi, i-l+1);
        }
        return maxi;
    }
};
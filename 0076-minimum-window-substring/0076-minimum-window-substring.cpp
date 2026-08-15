class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int mini = INT_MAX;
        int cnt = 0;
        int l = 0;
        int sidx = 0;
        unordered_map<char, int> mp;
        
        for(int x : t) {
            mp[x]++;
        }
        for(int i = 0; i < n; i++) {
            if(mp[s[i]] > 0) cnt++;
            mp[s[i]]--;
            while(cnt == m) {
                if(i - l +1 < mini) {
                    mini = i-l+1;
                    sidx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                l++;
            }
        }
        if(mini == INT_MAX) return "";
        return s.substr(sidx, mini);
    }
};
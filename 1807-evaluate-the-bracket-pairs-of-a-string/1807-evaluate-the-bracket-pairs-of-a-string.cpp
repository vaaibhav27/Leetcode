class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans = "";

        int i = 0;

        while (i < s.length()) {

            if (s[i] != '(') {
                ans += s[i];
                i++;
            }
            else {
                i++;

                string key = "";

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                i++;

                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += "?";
                }
            }
        }

        return ans;
    }
};
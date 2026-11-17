class Solution {
public:

    void solve(int index, int parts, string s,
               string current, vector<string>& ans) {

        if(parts == 4) {
            if(index == s.size()) {
                ans.push_back(current);
            }
            return;
        }

        for(int len = 1; len <= 3; len++) {

            if(index + len > s.size())
                break;

            string temp = s.substr(index, len);

            if(temp.size() > 1 && temp[0] == '0')
                break;

            int num = stoi(temp);

            if(num > 255)
                break;

            if(current.empty()) {
                solve(index + len, parts + 1, s,
                      temp, ans);
            }
            else {
                solve(index + len, parts + 1, s,
                      current + "." + temp, ans);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> ans;

        solve(0, 0, s, "", ans);

        return ans;
    }
};
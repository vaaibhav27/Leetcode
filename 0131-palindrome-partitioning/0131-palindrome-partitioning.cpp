class Solution {
public:
    void solve(string s, vector<vector<string>> &ans, vector<string> &curr, int ind) {
        if(ind == s.size()) {
            ans.push_back(curr);
            return;
        }
        for(int i = ind; i < s.size(); i++) {
            if(ispalindrome(s, ind, i)) {
                curr.push_back(s.substr(ind, i-ind+1));
                solve(s, ans, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    bool ispalindrome(string s, int st, int end) {
        while(st <= end) {
            if(s[st] != s[end]) return false;
            st++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;

        solve(s, ans, curr, 0);
        return ans;
    }
};
class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;

    bool solve(int i, string &s) {
        if (i == s.size()) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        string temp = "";

        for (int j = i; j < s.size(); j++) {
            temp += s[j];

            if (st.count(temp)) {
                if (solve(j + 1, s)) {
                    return dp[i] = 1;
                }
            }
        }

        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto &word : wordDict) {
            st.insert(word);
        }

        dp.assign(s.size(), -1);

        return solve(0, s);
    }
};

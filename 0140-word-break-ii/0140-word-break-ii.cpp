
class Solution {
public:
    unordered_set<string> st;

    void solve(int i, string &s, string path, vector<string>& ans) {
        if (i == s.size()) {
            ans.push_back(path);
            return;
        }

        string temp = "";

        for (int j = i; j < s.size(); j++) {
            temp += s[j];

            if (st.count(temp)) {
                string newPath = path;

                if (!newPath.empty()) {
                    newPath += " ";
                }

                newPath += temp;

                solve(j + 1, s, newPath, ans);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto &word : wordDict) {
            st.insert(word);
        }

        vector<string> ans;

        solve(0, s, "", ans);

        return ans;
    }
};

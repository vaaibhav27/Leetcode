class Solution {
public:
    void gen(string &arr, vector<string> &ans, int open, int close, int n) {
        if(arr.length() == 2 *n) {
            ans.push_back(arr);
            return;
        }

        if(open < n) {
            arr.push_back('(');
            gen(arr, ans, open+1, close, n);
            arr.pop_back();
        }
        if(close < open) {
            arr.push_back(')');
            gen(arr, ans, open, close + 1, n);
            arr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string arr = "";
        vector<string> ans;
        gen(arr, ans, 0, 0, n);
        return ans;
    }
};
class Solution {
public:
    void solve(vector<int> &candidates, int target, int i, vector<vector<int>> &ans, vector<int> &curr, int sum) {
        if(i == candidates.size()) {
            if(sum == target) {
                ans.push_back(curr);
            }
            return;
        }

        if(sum <= target) {
            curr.push_back(candidates[i]);
            solve(candidates, target, i, ans, curr, sum + candidates[i]);
            curr.pop_back();
        }
        solve(candidates, target, i + 1, ans, curr, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, 0, ans, curr, 0);

        return ans;
    }
};
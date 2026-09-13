class Solution {
public:
    void gen(vector<int>& candidates, int n, int ind, vector<vector<int>> &ans, vector<int> &curr, int target) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(ind == n) {
            return;
        }
        if(candidates[ind] <= target) {
            curr.push_back(candidates[ind]);
            gen(candidates, n, ind, ans, curr, target - candidates[ind]);
            curr.pop_back();
        }
        gen(candidates, n, ind + 1, ans, curr, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> curr;
        gen(candidates, n, 0, ans, curr, target);
        return ans;
    }
};
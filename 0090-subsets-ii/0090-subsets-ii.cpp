class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, vector<int> &curr, int i) {
       
        ans.push_back(curr);
         
        for(int ind = i; ind < nums.size(); ind++) {
            if(ind > i && nums[ind] == nums[ind-1]) continue;

            curr.push_back(nums[ind]);
            solve(nums, ans, curr, ind + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(nums, ans, curr, 0);
        return ans;
    }
};
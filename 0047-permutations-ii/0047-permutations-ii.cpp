class Solution {
public:

    void backtrack(vector<int>& nums, vector<int>& temp,
                   vector<vector<int>>& ans, vector<bool>& used) {

        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(used[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;

            temp.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, temp, ans, used);

            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        backtrack(nums, temp, ans, used);

        return ans;
    }
};
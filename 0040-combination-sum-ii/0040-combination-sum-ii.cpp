class Solution {
public:
    void gen(vector<int> &nums, vector<int> &arr, int ind, int s, vector<vector<int>> &ans, int k) {
    
            if(s == k) {
                ans.push_back(arr);
                return;
            }

        for(int i = ind; i< nums.size(); i++) {
            if(i > ind && nums[i] == nums[i-1]) continue;
            if(s + nums[i] > k) break;
            arr.push_back(nums[i]);

            gen(nums, arr, i+1, s+nums[i], ans, k);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        gen(nums, arr, 0, 0, ans, target);
        return ans;
    }
};
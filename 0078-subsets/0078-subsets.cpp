class Solution {
public:
    void gen(vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans, int i) {
        if(i >= nums.size()) {
            ans.push_back(arr);
            return;
        }

        gen(nums, arr, ans, i+1);
        arr.push_back(nums[i]);
        gen(nums, arr, ans, i+1);
        arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> ans;
        gen(nums, arr, ans, 0);
        return ans;
    }
};
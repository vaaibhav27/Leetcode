class Solution {
public:
    void gen(vector<int> &nums, vector<int> &arr, int ind, vector<vector<int>> &ans) 
    {
        ans.push_back(arr);

        for(int i = ind; i<nums.size(); i++) 
        {
            if(i > ind && nums[i] == nums[i-1]) continue;

            arr.push_back(nums[i]);
            gen(nums, arr, i+1, ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> arr;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        gen(nums, arr, 0, ans);
        return ans;
    }
};
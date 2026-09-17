class Solution {
public: 
    void gen(string &nums, string &arr, int ind, vector<string> &ans, string mapping[]) {
        if(ind >= nums.length()) {
            ans.push_back(arr);
            return;
        }

        int num = nums[ind] - '0';
        string value = mapping[num];

        for(int i = 0; i< value.length(); i++) {
            arr.push_back(value[i]);
            gen(nums, arr, ind+1, ans, mapping);
            arr.pop_back();
        }

    }
    vector<string> letterCombinations(string nums) {
        vector<string> ans;
        if(nums.length() == 0) return ans;
        string arr = "";
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        gen(nums, arr, 0, ans, mapping);
        return ans;
    }
};
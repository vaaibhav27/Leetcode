class Solution {
public:
    void gen(int n, vector<int> &arr, int k, int ind, int s, vector<vector<int>> &ans) {
        if(arr.size() == k) {
            if(s == n) {
                ans.push_back(arr);
            }
            return;
        }

        for(int i = ind; i<=9; i++) {
            if(s+ i > n) break;

            arr.push_back(i);
            gen(n, arr, k, i+1, s+i, ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        vector<vector<int>> ans;
        gen(n, arr, k, 1, 0, ans);
        return ans;
    }
};

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        int n = nums.size();
        int start = 0;

        for (int i = 1; i <= n; i++) {

            if (i == n || (long long)nums[i] != (long long)nums[i - 1] + 1) {

                if (start == i - 1) {
                    ans.push_back(to_string(nums[start]));
                }
                else {
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
                }

                start = i;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0, c2 = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == 1) {
                c1++;
                c2 = max(c1, c2);
            }
            else {
                c1 = 0;
            }
        }
        return c2;
    }
};
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long f = LLONG_MIN;
        long long s = LLONG_MIN;
        long long t = LLONG_MIN;
        for(int i = 0; i < n; i++) {
            if(nums[i] == f || nums[i] == s || nums[i] == t) continue;
            if(nums[i] > f) {
                t = s;
                s = f;
                f = nums[i];
            }
            else if (nums[i] > s) {
                t = s;
                s = nums[i];
            }
            else if(nums[i] > t) t = nums[i];
        }
        if(t == LLONG_MIN) return f;
        else return t;
    }
};
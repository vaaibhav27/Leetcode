class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(cnt == 0) c1 = nums[i];
            if(c1 == nums[i]) cnt++;
            else cnt --;
        }
        return c1;
    }
};
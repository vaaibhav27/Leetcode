class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int multi = k;
        while(true) {
            bool flag = false;
            for(int x : nums) {
                if(x == multi) {
                    flag = true;
                    break;
                }
            }
            if(flag == false) return multi;
            multi += k;
        }
    }
};
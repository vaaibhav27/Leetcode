class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        int p = 0, ng = 1;
        for(int i = 0; i<n; i++){
            if (nums[i]>0){
                temp[p] = nums[i];
                p+=2;
            }
            else {
                temp[ng] = nums[i];
                ng+=2;
            }
        }
        return temp;
    }
};
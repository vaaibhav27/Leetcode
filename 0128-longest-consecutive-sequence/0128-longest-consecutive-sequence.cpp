class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
        for(int i = 0; i<n; i++) {
            st.insert(nums[i]);
        }
        int l = 1;
        for(auto it: st) {
            if(st.find(it-1) == st.end()) {
                int cnt = 1;
                int x = it;
                while(st.find(x+1)!= st.end()) {
                    cnt++;
                    x+=1;
                }
                l = max(cnt, l);
            }
        }
        return l;    
    }
};
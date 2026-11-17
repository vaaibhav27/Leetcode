class Solution {
public:
    int titleToNumber(string columnTitle) {

        int ans = 0;

        for(int i = 0; i < columnTitle.size(); i++) {

            int value = columnTitle[i] - 'A' + 1;

            ans = ans * 26 + value;
        }

        return ans;
    }
};

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();

        vector<pair<int,int>> a, b;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1) {
                    a.push_back({i, j});
                }

                if(img2[i][j] == 1) {
                    b.push_back({i, j});
                }
            }
        }

        map<pair<int,int>, int> mp;

        int ans = 0;

        for(auto p1 : a) {
            for(auto p2 : b) {

                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;

                mp[{dr, dc}]++;

                ans = max(ans, mp[{dr, dc}]);
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>>ans(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans[i][j] = image[i][j];
            }
        }
        q.push({sr, sc});
        visited[sr][sc] = 1;
        ans[sr][sc] = color;
        int clr = image[sr][sc];
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            int nrow[] = {-1, 0, +1, 0};
            int ncol[] = {0, +1, 0, -1};
            q.pop();
            for(int i = 0; i<4; i++) {
                int row = nrow[i] + r;
                int col = ncol[i] + c;
                if(row >= 0 && row < n && col >= 0  && col < m
                && visited[row][col] == 0 && image[row][col] == clr) {
                    q.push({row, col});
                    visited[row][col] = 1;
                    ans[row][col] = color;
                }
            }
        }
        return ans;
    }
};
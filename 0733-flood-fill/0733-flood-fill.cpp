class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> adj(n, vector<int> (m));
        if(image[sr][sc] == color)
            return image;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                adj[i][j] = image[i][j];
            }
        }
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int clr = image[sr][sc];
        adj[sr][sc] = color;

        int row[] = {-1, 0, +1, 0};
        int col[] = {0, +1, 0, -1};

        while(!q.empty()) {
            int rw = q.front().first;
            int cl = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {
                int r = row[i] + rw;
                int c = col[i] + cl;

                if(r >=0 && r < n && c >= 0 && c < m
                && adj[r][c] == clr) {
                    adj[r][c] = color;
                    q.push({r, c});
                }
            }
        }
        return adj;
    }
};
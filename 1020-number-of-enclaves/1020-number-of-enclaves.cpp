class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int land = 0;
        int sea = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) land++;
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                    cnt++;
                }
                
            }
        }

        int row[] = {-1, 0, +1, 0};
        int col[] = {0, +1, 0, -1};
        
        while(!q.empty()) {
            int rw = q.front().first;
            int cl = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {
                int r = rw + row[i];
                int c = cl + col[i];

                if(r >=0 && r < n && c >= 0 && c < m
                && grid[r][c] == 1) {
                    q.push({r, c});
                    grid[r][c] = 0;
                    cnt++;
                }
            }
        }
        return land - cnt;
    }
};
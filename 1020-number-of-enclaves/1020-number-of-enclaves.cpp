class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        int land = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) cnt++;

                if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j});
                    land++;
                }
            }
        }
        int rw[] = {-1, 1, 0, 0};
        int cl[] = {0, 0, -1, 1}; 

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int row = r + rw[i];
                int col = c + cl[i];

                if(row >= 0 && row < n && col >= 0 && col < m
                && grid[row][col] == 1) {
                    grid[row][col] = 0;
                    q.push({row, col});
                    land++;
                }
            }
        }
        return cnt - land;
    }
};
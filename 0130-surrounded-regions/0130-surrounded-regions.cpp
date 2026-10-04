class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || i == n-1 || j == 0 || j == m-1)
                && board[i][j] == 'O') {
                    board[i][j] = '#';
                    q.push({i, j});
                }
            }
        }

        int rw[] = {-1, 1, 0, 0};
        int cl[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {
                int r = row + rw[i];
                int c = col + cl[i];

                if(r >= 0 && r < n && c >= 0 && c < m
                && board[r][c] == 'O') {
                    board[r][c] = '#';
                    q.push({r, c});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
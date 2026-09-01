class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int sr = 0, sc = 0;
        int cnt = 0;

        vector<vector<int>> id(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        queue<tuple<int,int,int,int>> q;

        int fullMask = (1 << cnt) - 1;

        q.push({sr, sc, energy, fullMask});

        vector<vector<vector<vector<bool>>>> visited(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        visited[sr][sc][energy][fullMask] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == 0)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy;
                    int newMask = mask;

                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }
                    else {
                        newEnergy = e - 1;
                    }

                    if (classroom[nr][nc] == 'L') {
                        newMask &= ~(1 << id[nr][nc]);
                    }

                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};
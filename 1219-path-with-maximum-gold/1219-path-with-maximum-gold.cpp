class Solution {
    int ans = 0, d[15][15], m, n;

public:
    bool OOB(int r, int c) { return r < 0 || r >= m || c < 0 || c >= n; }
    bool isOver(int r, int c, vector<vector<int>>& grid) {
        for (int i = 0; i < 4; i++) {
            int nx = "2101"[i] - '1' + r;
            int ny = "1012"[i] - '1' + c;

            if (OOB(nx, ny))
                continue;
            if (d[nx][ny] == 0 && grid[nx][ny])
                return false;
        }

        return true;
    }
    void sol(int r, int c, int sum, vector<vector<int>>& grid) {
        if (isOver(r, c, grid)) {
            ans = max(ans, sum);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = "2101"[i] - '1' + r;
            int ny = "1012"[i] - '1' + c;
            if (OOB(nx, ny) || d[nx][ny] || grid[nx][ny] == 0) continue;
            d[nx][ny] = 1;
            sol(nx, ny, sum + grid[nx][ny], grid);
            d[nx][ny] = 0;
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < 15; i++)
            fill(d[i], d[i] + 15, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                d[i][j] = 1;
                sol(i, j, grid[i][j], grid);
                d[i][j] = 0;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int row = heights.size(), col = heights[0].size();
        queue<pair<int, int>> q;
        int dx[4] = { 1, 0, -1, 0}, dy[4] = { 0, 1, 0, -1 }; 
        int vis[row][col];
        for (int i = 0; i < row; i++)
            fill(vis[i], vis[i] + col, 2000000);
        
        q.push({0, 0});
        vis[0][0] = 0;
        while (q.size()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
                if (vis[nx][ny] > max(vis[x][y], abs(heights[x][y] - heights[nx][ny]))) {
                    q.push({nx, ny});
                    vis[nx][ny] = max(vis[x][y], abs(heights[x][y] - heights[nx][ny]));
                }
            }
        }

        return vis[row - 1][col - 1];
    }
};
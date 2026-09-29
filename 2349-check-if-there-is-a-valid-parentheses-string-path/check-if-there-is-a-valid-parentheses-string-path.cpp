class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        vector<vector<char>> dp(n, vector<char>(m + n, 0));
        vector<vector<vector<char>>> reach(m, vector<vector<char>>(n, vector<char>(m + n + 1, 0)));
        reach[0][0][1] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int delta = (grid[i][j] == '(') ? 1 : -1;
                for (int b = 0; b <= m + n; b++) {
                    bool fromUp = (i > 0) && (b - delta >= 0) && (b - delta <= m + n) && reach[i-1][j][b - delta];
                    bool fromLeft = (j > 0) && (b - delta >= 0) && (b - delta <= m + n) && reach[i][j-1][b - delta];
                    if ((fromUp || fromLeft) && b >= 0) {
                        reach[i][j][b] = 1;
                    }
                }
            }
        }
        return reach[m-1][n-1][0];
    }
};
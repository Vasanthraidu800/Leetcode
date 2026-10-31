class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;

    vector<vector<vector<int>>> memo;

    int solve(int i, int j, int d, vector<vector<int>>& grid) {
        if (i >= m || j >= n)
            return -1;

        if (grid[i][j] == 0)
            return i * n + j;

        if (memo[i][j][d] != -2)
            return memo[i][j][d];

        int ans;

        if (d == 0)
            ans = solve(i + 1, j, 1, grid);
        else
            ans = solve(i, j + 1, 0, grid);

        return memo[i][j][d] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memo.assign(m, vector<vector<int>>(n, vector<int>(2, -2)));

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0)
                    continue;

                // Move right
                int x = solve(i, j + 1, 0, grid);

                if (x != -1) {
                    int r = x / n;
                    int c = x % n;
                    dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                }

                // Move down
                x = solve(i + 1, j, 1, grid);

                if (x != -1) {
                    int r = x / n;
                    int c = x % n;
                    dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
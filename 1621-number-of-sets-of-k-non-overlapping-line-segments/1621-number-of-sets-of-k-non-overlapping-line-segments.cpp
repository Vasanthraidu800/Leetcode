class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1000000007;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int j = 1; j <= k; j++) {
            long long sum = 0;

            for (int i = 1; i <= n; i++) {
                dp[i][j] = dp[i - 1][j] + sum;
                dp[i][j] %= MOD;

                sum += dp[i][j - 1];
                sum %= MOD;
            }
        }

        return dp[n][k];
    }
};
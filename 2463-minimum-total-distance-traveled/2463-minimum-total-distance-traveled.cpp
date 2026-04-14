class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) 
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size();
        int m = factory.size();
        // dp[i][j] = min distance to fix first i robots using first j factories
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));

        // base case: 0 robots → 0 distance
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int j = 1; j <= m; j++) {
            int pos = factory[j - 1][0];
            int limit = factory[j - 1][1];

            for (int i = 0; i <= n; i++) {

                // Case 1--- skip this factory
                dp[i][j] = dp[i][j - 1];

                long long dist = 0;

                // Case 2--- assign k robots to this factory
                for (int k = 1; k <= limit && k <= i; k++) {
                    dist += abs(robot[i - k] - pos);

                    dp[i][j] = min(dp[i][j],
                                   dp[i - k][j - 1] + dist);
                }
            }
        }

        return dp[n][m];
    }
};
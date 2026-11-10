class Solution {
public:
    vector<int> dp;

    int solve(int i, int n, vector<int>& costs) {
        if (i == n) return 0;
        if (i > n) return 1e9;
        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for (int jump = 1; jump <= 3; jump++) {
            int j = i + jump;
            if (j <= n) {
                int cost = costs[j] + (j - i) * (j - i);
                ans = min(ans, cost + solve(j, n, costs));
            }
        }
        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        if ((int)costs.size() == n) {
            costs.insert(costs.begin(), 0);
        }
        dp.assign(n + 1, -1);
        return solve(0, n, costs);
    }
};
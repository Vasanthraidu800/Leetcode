class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            return x[1] < y[1];
        });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] = lower_bound(
                ends.begin(),
                ends.end(),
                a[i][0]
            ) - ends.begin();
        }

        vector<vector<Node>> dp(5, vector<Node>(n + 1));

        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= 4; k++)
                dp[k][i] = dp[k][i - 1];

            for (int k = 1; k <= 4; k++) {
                Node cur = dp[k - 1][prev[i - 1]];
                cur.score += a[i - 1][2];
                cur.ids.push_back(a[i - 1][3]);
                sort(cur.ids.begin(), cur.ids.end());

                if (better(cur, dp[k][i]))
                    dp[k][i] = cur;
            }
        }

        return dp[4][n].ids;
    }
};
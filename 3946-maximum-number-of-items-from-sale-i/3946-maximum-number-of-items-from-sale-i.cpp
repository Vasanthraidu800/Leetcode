class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mn = 1501;
        vector<int> gain(n);

        for(auto &x : items)
            mn = min(mn, x[1]);

        for(int i = 0; i < n; i++) {
            gain[i] = 1;
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0)
                    gain[i]++;
            }
        }

        vector<int> dp(budget + 1);
        for(int b = 0; b <= budget; b++)
            dp[b] = b / mn;

        for(int i = 0; i < n; i++) {
            int cost = items[i][1];
            if(gain[i] > cost / mn) {
                for(int b = budget; b >= cost; b--)
                    dp[b] = max(dp[b], dp[b - cost] + gain[i]);
            }
        }

        return dp[budget];
    }
};
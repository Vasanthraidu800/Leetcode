class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = n;

        vector<int> freq(mx + 1, 0);

        for (int i = 0; i < n; i++)
            freq[items[i][0]]++;

        for (int i = 1; i <= mx; i++) {
            for (int j = i * 2; j <= mx; j += i) {
                freq[i] += freq[j];
            }
        }

        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int mn = items[0][1];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            if (price > 2 * mn)
                break;

            int cnt = freq[factor] - 1;
            int take = min(cnt, budget / price);

            ans += take * 2;
            budget -= take * price;
        }

        ans += budget / mn;
        return ans;
    }
};
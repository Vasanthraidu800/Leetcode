class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sa(n), r(n), t(n), pos(n), lcp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            r[i] = nums[i];
        }

        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int a, int b) {
                if (r[a] != r[b])
                    return r[a] < r[b];

                int x = a + k < n ? r[a + k] : -1;
                int y = b + k < n ? r[b + k] : -1;
                return x < y;
            };

            sort(sa.begin(), sa.end(), cmp);

            t[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                t[sa[i]] = t[sa[i - 1]] + cmp(sa[i - 1], sa[i]);

            r = t;

            if (r[sa[n - 1]] == n - 1)
                break;
        }

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int x = pos[i];

            if (x == 0) {
                h = 0;
                continue;
            }

            int j = sa[x - 1];

            while (i + h < n && j + h < n && nums[i + h] == nums[j + h])
                h++;

            lcp[x] = h;

            if (h > 0)
                h--;
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            int mx = lcp[i];
            if (i + 1 < n)
                mx = max(mx, lcp[i + 1]);

            if (mx < n - sa[i])
                ans = min(ans, mx + 1);
        }

        return ans;
    }
};
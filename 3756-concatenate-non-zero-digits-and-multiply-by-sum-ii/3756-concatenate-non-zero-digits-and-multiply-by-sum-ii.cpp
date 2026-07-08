class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;

        int m = s.size();

        vector<int> pos, dig;

        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                dig.push_back(s[i] - '0');
            }
        }

        int n = pos.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefVal(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefSum[i] = prefSum[i - 1] + dig[i - 1];
            prefVal[i] = (prefVal[i - 1] * 10 + dig[i - 1]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long sum = prefSum[R + 1] - prefSum[L];

            long long x = prefVal[R + 1];
            x = (x - prefVal[L] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};
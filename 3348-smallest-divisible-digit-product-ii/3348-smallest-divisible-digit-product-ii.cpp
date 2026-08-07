class Solution {
public:
    unordered_map<long long, int> dp;
    string s;
    int n;

    int f(long long x) {
        if (x == 1) return 0;
        if (dp.count(x)) return dp[x];

        int ans = 1e9;

        for (int d = 2; d <= 9; d++) {
            long long y = x / gcd(x, (long long)d);
            if (y < x)
                ans = min(ans, 1 + f(y));
        }

        return dp[x] = ans;
    }

    bool dfs(int i, bool big, long long rem, string &ans) {
        if (i == n)
            return rem == 1;

        int st = big ? 1 : s[i] - '0';
        if (st == 0) st = 1;

        for (int d = st; d <= 9; d++) {
            long long nr = rem / gcd(rem, (long long)d);

            if (f(nr) > n - i - 1)
                continue;

            ans.push_back(char('0' + d));

            if (dfs(i + 1, big || d > s[i] - '0', nr, ans))
                return true;

            ans.pop_back();
        }

        return false;
    }

    string build(int len, long long rem) {
        string ans;

        for (int i = 0; i < len; i++) {
            for (int d = 1; d <= 9; d++) {
                long long nr = rem / gcd(rem, (long long)d);

                if (f(nr) <= len - i - 1) {
                    ans.push_back(char('0' + d));
                    rem = nr;
                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {
        long long x = t;

        for (int p : {2, 3, 5, 7}) {
            while (x % p == 0)
                x /= p;
        }

        if (x != 1)
            return "-1";

        s = num;
        n = s.size();

        string ans;

        if (dfs(0, false, t, ans))
            return ans;

        int len = max(n + 1, f(t));
        return build(len, t);
    }
};
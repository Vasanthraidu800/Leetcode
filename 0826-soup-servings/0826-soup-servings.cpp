class Solution {
public:
    double soupServings(int n) {
        if (n == 0) return 0.5; // both empty at start
        int units = (n + 24) / 25; // scale to 25 mL units
        if (units >= 200) return 1.0; // probability ~1 for large n

        unordered_map<long long, double> memo;
        function<double(int,int)> dfs = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5; // both empty same turn
            if (a <= 0) return 1.0;           // A empty first
            if (b <= 0) return 0.0;           // B empty first
            long long key = ((long long)a << 32) | b;
            if (memo.count(key)) return memo[key];
            double res = 0.0;
            res += dfs(a - 4, b - 0);
            res += dfs(a - 3, b - 1);
            res += dfs(a - 2, b - 2);
            res += dfs(a - 1, b - 3);
            return memo[key] = 0.25 * res;
        };

        return dfs(units, units);
    }
};

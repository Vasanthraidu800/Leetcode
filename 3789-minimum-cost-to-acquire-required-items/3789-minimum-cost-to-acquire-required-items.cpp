class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int need1, int need2) {

        long long ans = LLONG_MAX;
        long long k1 = 0;
        long long k2 = min(need1, need2);
        long long k3 = max(need1, need2);

        auto calc = [&](long long k) {
            long long r1 = max(0LL, (long long)need1 - k);
            long long r2 = max(0LL, (long long)need2 - k);
            return k * cb + r1 * c1 + r2 * c2;
        };

        ans = min(ans, calc(k1));
        ans = min(ans, calc(k2));
        ans = min(ans, calc(k3));

        return ans;
    }
};
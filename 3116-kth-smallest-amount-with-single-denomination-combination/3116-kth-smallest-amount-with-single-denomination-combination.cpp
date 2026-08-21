class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b, long long limit) {
        long long g = gcdll(a, b);
        a /= g;


        if (a > limit / b) return limit + 1;
        return a * b;
    }

    long long count(long long x, const vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;


        for (int mask = 1; mask < (1 << n); ++mask) {
            long long curLCM = 1;
            int bits = 0;
            bool tooLarge = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    ++bits;
                    curLCM = lcm(curLCM, coins[i], x);

                    if (curLCM > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge) continue;

            long long multiples = x / curLCM;

            if (bits & 1)
                ans += multiples;
            else
                ans -= multiples;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
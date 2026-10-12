
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long mod = 1e9 + 7;
        vector<long long> a(k, 0);

        for (int i = 0; i < 32; i++) {
            int cnt = 0;

            for (int x : nums) {
                if (x & (1LL << i))
                    cnt++;
            }

            for (int j = 0; j < min(k, cnt); j++) {
                a[j] |= (1LL << i);
            }
        }

        long long ans = 0;

        for (long long x : a) {
            ans = (ans + x * x % mod) % mod;
        }

        return ans;
    }
};

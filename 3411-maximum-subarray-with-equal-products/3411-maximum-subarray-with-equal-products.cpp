class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;

        for (int i = 0; i < n; i++) {
            long double p = 1;
            long long l = 1;
            int g = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                p *= x;
                g = gcd(g, x);
                l = l / gcd(l, (long long)x) * x;

                if (p == (long double)l * g)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
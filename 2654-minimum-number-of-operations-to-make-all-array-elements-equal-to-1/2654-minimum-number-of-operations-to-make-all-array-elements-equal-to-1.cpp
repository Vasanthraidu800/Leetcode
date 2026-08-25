class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g = nums[0];
        for (int i = 1; i < n; i++)
            g = gcd(g, nums[i]);
        if (g != 1)
            return -1;
        int cnt = 0;
        for (int x : nums)
            if (x == 1)
                cnt++;
        if (cnt > 0)
            return n - cnt;
        int len = n;
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);

                if (g == 1) {
                    len = min(len, j - i + 1);
                    break;
                }
            }
        }
        return (len - 1) + (n - 1);
    }
};
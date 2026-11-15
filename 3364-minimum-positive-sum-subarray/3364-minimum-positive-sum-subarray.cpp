
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = l; j <= r && i + j <= n; j++) {
                int sum = pre[i + j] - pre[i];

                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};

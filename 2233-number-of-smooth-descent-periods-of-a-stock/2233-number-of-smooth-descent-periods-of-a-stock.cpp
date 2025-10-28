class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;
        int cnt = 1;
        int prev = nums[0];

        for (int i = 1; i < n; i++) {
            if (prev - nums[i] == 1) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            prev = nums[i];
            ans += cnt;
        }
        return ans;
    }
};
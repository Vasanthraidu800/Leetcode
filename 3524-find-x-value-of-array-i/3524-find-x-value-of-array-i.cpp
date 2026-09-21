class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> ans(k, 0);
        vector<long long> cnt(k, 0);

        for(int i = 0; i < n; i++)
        {
            vector<long long> next(k, 0);

            // subarray containing only nums[i]
            next[nums[i] % k]++;

            // extend previous subarrays
            for(int r = 0; r < k; r++)
            {
                int x = (r * (nums[i] % k)) % k;
                next[x] += cnt[r];
            }

            // add all subarrays ending at i
            for(int r = 0; r < k; r++)
            {
                ans[r] += next[r];
            }

            cnt = next;
        }

        return ans;
    }
};
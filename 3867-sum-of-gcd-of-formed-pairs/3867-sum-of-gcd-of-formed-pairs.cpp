class Solution {
public:
    int find_gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            ans.push_back(find_gcd(nums[i], mx));
        }

        sort(ans.begin(), ans.end());

        long long sum = 0;
        for (int i = 0; i < n / 2; i++) {
            sum += find_gcd(ans[i], ans[n - 1 - i]);
        }

        return sum;
    }
};
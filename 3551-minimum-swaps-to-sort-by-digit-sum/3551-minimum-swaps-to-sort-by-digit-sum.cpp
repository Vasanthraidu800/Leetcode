class Solution {
    int sum(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {{sum(nums[i]), nums[i]}, i};
        }
        
        sort(a.begin(), a.end());
        
        vector<bool> vis(n, false);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (vis[i] || a[i].second == i) continue;
            
            int len = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = a[j].second;
                len++;
            }
            if (len > 1) ans += len - 1;
        }
        
        return ans;
    }
};
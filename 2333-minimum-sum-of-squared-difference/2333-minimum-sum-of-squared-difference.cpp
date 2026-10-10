class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> f(100001, 0);
        long long k = (long long)k1 + k2;
        
        for (int i = 0; i < nums1.size(); i++)
            f[abs(nums1[i] - nums2[i])]++;
        
        for (int i = 100000; i > 0 && k > 0; i--) {
            if (f[i] == 0) continue;
            
            long long cnt = min(f[i], k);
            f[i] -= cnt;
            f[i - 1] += cnt;
            k -= cnt;
        }
        
        if (k > 0) return 0;
        
        long long ans = 0;
        for (int i = 1; i <= 100000; i++)
            ans += f[i] * i * i;
        
        return ans;
    }
};
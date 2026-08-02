class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, mx = 0;
        
        for(int x : nums) {
            ans += __builtin_popcount(x);
            mx = max(mx, x);
        }
        
        while(mx > 1) {
            ans++;
            mx /= 2;
        }
        
        return ans;
    }
};
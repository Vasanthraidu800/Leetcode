class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int l = 0; l < n; ++l) {
            unordered_map<int,int> even, odd;
            int de = 0, doo = 0; 
            for (int r = l; r < n; ++r) {
                int x = nums[r];

                if (x % 2 == 0) {
                    if (even[x] == 0) de++;
                    even[x]++;
                } else {
                    if (odd[x] == 0) doo++;
                    odd[x]++;
                }

                if (de == doo) {
                    ans = max(ans, r - l + 1);
                }
            }
        }
        return ans;
    }
};

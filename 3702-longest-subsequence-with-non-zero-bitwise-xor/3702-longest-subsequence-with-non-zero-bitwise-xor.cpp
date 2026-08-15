class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool ok = false;

        for (int a : nums) {
            x ^= a;
            if (a != 0) ok = true;
        }

        if (x != 0) return nums.size();
        if (ok) return nums.size() - 1;
        return 0;
    }
};
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        int mx = 0;

        for (int x : nums) {
            ans += Integer.bitCount(x);
            mx = Math.max(mx, x);
        }

        while (mx > 1) {
            ans++;
            mx /= 2;
        }

        return ans;
    }
}
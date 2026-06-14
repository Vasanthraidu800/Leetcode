class Solution {
public:
    int minOperations(int n) {
        int ans = 0;

        while (n > 0) {
        
            if ((n & (n - 1)) == 0)
                return ans + 1;

            int lowbit = n & -n;

            if (n & (lowbit << 1))
                n += lowbit;
            else
                n -= lowbit;

            ans++;
        }

        return ans;
    }
};
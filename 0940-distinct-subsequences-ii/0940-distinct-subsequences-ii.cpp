class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        for(char c : s) {
            long long sum = 1;

            for(int i = 0; i < 26; i++)
                sum = (sum + dp[i]) % MOD;

            dp[c - 'a'] = sum;
        }

        long long ans = 0;

        for(int i = 0; i < 26; i++)
            ans = (ans + dp[i]) % MOD;

        return ans;
    }
};
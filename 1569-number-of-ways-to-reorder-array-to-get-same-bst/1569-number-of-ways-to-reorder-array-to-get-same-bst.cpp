class Solution {
private:
    long long MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long dfs(const vector<int>& arr) {
        if (arr.size() <= 2) return 1;

        int root = arr[0];
        vector<int> left, right;
        
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < root) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }

        long long l_len = left.size();
        long long r_len = right.size();

        long long ways = comb[l_len + r_len][l_len];
        ways = (ways * dfs(left)) % MOD;
        ways = (ways * dfs(right)) % MOD;

        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
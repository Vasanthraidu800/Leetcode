class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        vector<int> arr;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        int size = arr.size();
        vector<int> prefix(size, 1);
        vector<int> suffix(size, 1);

        // Prefix product
        for(int i = 1; i < size; i++) {
            long long val = (long long)prefix[i-1] * arr[i-1];
            prefix[i] = val % mod;
        }

        // Suffix product
        for(int i = size-2; i >= 0; i--) {
            long long val = (long long)suffix[i+1] * arr[i+1];
            suffix[i] = val % mod;
        }

        // result matrix
        vector<vector<int>> result(n, vector<int>(m));
        int k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                long long val = (long long)prefix[k] * suffix[k];
                result[i][j] = val % mod;
                k++;
            }
        }

        return result;
    }
};
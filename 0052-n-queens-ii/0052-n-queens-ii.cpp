class Solution {
public:
    int ans = 0;

    void solve(int row, int n, vector<int>& col,
               vector<int>& d1, vector<int>& d2) {
        if (row == n) {
            ans++;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (col[j] || d1[row - j + n - 1] || d2[row + j])
                continue;

            col[j] = d1[row - j + n - 1] = d2[row + j] = 1;

            solve(row + 1, n, col, d1, d2);

            col[j] = d1[row - j + n - 1] = d2[row + j] = 0;
        }
    }

    int totalNQueens(int n) {
        vector<int> col(n, 0);
        vector<int> d1(2 * n - 1, 0);
        vector<int> d2(2 * n - 1, 0);

        solve(0, n, col, d1, d2);
        return ans;
    }
};
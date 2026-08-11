class Solution {
public:
// function to rotate elements
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        k %= n;

        vector<int> temp;

        for(int i = k; i < n; i++)
            temp.push_back(v[i]);

        for(int i = 0; i < k; i++)
            temp.push_back(v[i]);

        v = temp;
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        int t = 0, b = m - 1;
        int l = 0, r = n - 1;

        while(t < b && l < r) {
            vector<int> v;

            // take top row
            for(int j = l; j <= r; j++)
                v.push_back(grid[t][j]);

            // take right column
            for(int i = t + 1; i <= b; i++)
                v.push_back(grid[i][r]);

            // take bottom row
            for(int j = r - 1; j >= l; j--)
                v.push_back(grid[b][j]);

            // take left column
            for(int i = b - 1; i > t; i--)
                v.push_back(grid[i][l]);

            rotate(v, k);

            int p = 0;

            // put top row
            for(int j = l; j <= r; j++)
                grid[t][j] = v[p++];

            // put right column
            for(int i = t + 1; i <= b; i++)
                grid[i][r] = v[p++];

            // put bottom row
            for(int j = r - 1; j >= l; j--)
                grid[b][j] = v[p++];

            // put left column
            for(int i = b - 1; i > t; i--)
                grid[i][l] = v[p++];

            // move to next layer
            t++;
            b--;
            l++;
            r--;
        }

        return grid;
    }
};
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
        int n = g.size();

        // main diagonal
        vector<int> d;
        for (int i = 0; i < n; i++) d.push_back(g[i][i]);
        sort(d.begin(), d.end(), greater<int>());
        for (int i = 0; i < n; i++) g[i][i] = d[i];

        // top-right
        for (int j = 1; j < n; j++) {
            d.clear();
            for (int i = 0, y = j; i < n && y < n; i++, y++) d.push_back(g[i][y]);
            sort(d.begin(), d.end());
            int k = 0;
            for (int i = 0, y = j; i < n && y < n; i++, y++) g[i][y] = d[k++];
        }

        // bottom-left
        for (int i = 1; i < n; i++) {
            d.clear();
            for (int x = i, y = 0; x < n && y < n; x++, y++) d.push_back(g[x][y]);
            sort(d.begin(), d.end(), greater<int>());
            int k = 0;
            for (int x = i, y = 0; x < n && y < n; x++, y++) g[x][y] = d[k++];
        }

        return g;
    }
};

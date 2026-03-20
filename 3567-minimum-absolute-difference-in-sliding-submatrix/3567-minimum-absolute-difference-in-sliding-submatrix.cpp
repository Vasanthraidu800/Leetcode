class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& g, int k) {
        
        int m = g.size();
        int n = g[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                
                vector<int> a;
            
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        a.push_back(g[x][y]);
                    }
                }
                

                sort(a.begin(), a.end());
                
                a.erase(unique(a.begin(), a.end()), a.end());
                
                int d = INT_MAX;
                
                for (int t = 1; t < a.size(); t++) {
                    d = min(d, a[t] - a[t - 1]);
                }
                
                if (d == INT_MAX) d = 0;
                
                ans[i][j] = d;
            }
        }
        
        return ans;
    }
};
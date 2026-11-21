class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> g(n), ng(n);

        for(int i = 1; i < n; i++)
            g[parent[i]].push_back(i);

        vector<int> np = parent;
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';
            int old = last[c];

            if(old != -1)
                np[u] = old;

            last[c] = u;

            for(int v : g[u])
                dfs(v);

            last[c] = old;
        };

        dfs(0);

        for(int i = 1; i < n; i++)
            ng[np[i]].push_back(i);

        vector<int> ans(n, 0);

        function<int(int)> calc = [&](int u) {
            ans[u] = 1;

            for(int v : ng[u])
                ans[u] += calc(v);

            return ans[u];
        };

        calc(0);
        return ans;
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& sw) {
        int n = s.size();
        //  graph
        vector<vector<int>> g(n);
        for (int i = 0; i < sw.size(); i++)
         {
            int a = sw[i][0];
            int b = sw[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> vis(n, 0);
        int ans = 0;
        // findIng the --> connected components
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) continue;

            vector<int> comp;
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            // bfs
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                comp.push_back(x);

                for (int j = 0; j < g[x].size(); j++) {
                    int nei = g[x][j];
                    if (vis[nei] == 0) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }

            // count source values in this component
            unordered_map<int, int> mp;
            for (int j = 0; j < comp.size(); j++) {
                mp[s[comp[j]]]++;
            }

            // trying to match target values
            for (int j = 0; j < comp.size(); j++) {
                int val = t[comp[j]];
                if (mp[val] > 0) {
                    mp[val]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};
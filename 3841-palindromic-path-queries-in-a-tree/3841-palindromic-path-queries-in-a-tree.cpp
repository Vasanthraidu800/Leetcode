class Solution {
    int n, T;
    vector<vector<int>> adj;
    vector<int> p, d, h, head, pos, tree;
    string s;

    int dfs(int u, int par, int dep) {
        p[u] = par; d[u] = dep;
        int sz = 1, max_sz = 0;
        for (int v : adj[u]) {
            if (v != par) {
                int sub = dfs(v, u, dep + 1);
                sz += sub;
                if (sub > max_sz) max_sz = sub, h[u] = v;
            }
        }
        return sz;
    }

    void decomp(int u, int h_top) {
        head[u] = h_top;
        pos[u] = T++;
        if (h[u] != -1) decomp(h[u], h_top);
        for (int v : adj[u]) {
            if (v != p[u] && v != h[u]) decomp(v, v);
        }
    }

    void build(int node, int l, int r) {
        if (l == r) return;
        int m = (l + r) >> 1;
        build(node << 1, l, m);
        build(node << 1 | 1, m + 1, r);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = val; return; }
        int m = (l + r) >> 1;
        if (idx <= m) update(node << 1, l, m, idx, val);
        else update(node << 1 | 1, m + 1, r, idx, val);
        tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int m = (l + r) >> 1;
        return query(node << 1, l, m, ql, qr) ^ query(node << 1 | 1, m + 1, r, ql, qr);
    }

    int get_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (d[head[u]] > d[head[v]]) swap(u, v);
            res ^= query(1, 0, n - 1, pos[head[v]], pos[v]);
            v = p[head[v]];
        }
        if (d[u] > d[v]) swap(u, v);
        return res ^ query(1, 0, n - 1, pos[u], pos[v]);
    }

public:
    vector<bool> palindromePath(int nodes, vector<vector<int>>& edges, string str, vector<string>& queries) {
        n = nodes; s = str; T = 0;
        adj.assign(n, {});
        for (auto& e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

        p.assign(n, -1); d.assign(n, 0); h.assign(n, -1); head.assign(n, 0); pos.assign(n, 0);
        dfs(0, -1, 0);
        decomp(0, 0);

        tree.assign(n << 2, 0);
        build(1, 0, n - 1);
        for (int i = 0; i < n; ++i) update(1, 0, n - 1, pos[i], 1 << (s[i] - 'a'));

        vector<bool> ans;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u; char c; ss >> u >> c;
                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int u, v; ss >> u >> v;
                int mask = get_path(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};
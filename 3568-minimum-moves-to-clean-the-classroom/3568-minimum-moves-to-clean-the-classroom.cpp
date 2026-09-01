class Solution {
public:
    int minMoves(vector<string>& a, int E) {
        int m = a.size(), n = a[0].size();
        vector<pair<int,int>> l;
        int sr, sc;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'S') sr = i, sc = j;
                else if (a[i][j] == 'L') l.push_back({i,j});
            }
        }

        int k = l.size();
        if (!k) return 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++)
            id[l[i].first][l[i].second] = i;

        int full = (1 << k) - 1;
        int M = 1 << k;

        struct Node {
            int r, c, mask, e;
        };

        queue<Node> q;

        // best[r][c][mask] = maximum energy reached
        vector<int> best(m * n * M, -1);

        auto idx = [&](int r, int c, int mask) {
            return (r * n + c) * M + mask;
        };

        q.push({sr, sc, 0, E});
        best[idx(sr, sc, 0)] = E;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == full)
                    return ans;

                if (e == 0)
                    continue;

                for (int z = 0; z < 4; z++) {
                    int nr = r + dr[z];
                    int nc = c + dc[z];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (a[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nm = mask;

                    if (a[nr][nc] == 'L')
                        nm |= 1 << id[nr][nc];

                    if (a[nr][nc] == 'R')
                        ne = E;

                    int p = idx(nr, nc, nm);

                    if (ne > best[p]) {
                        best[p] = ne;
                        q.push({nr, nc, nm, ne});
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};
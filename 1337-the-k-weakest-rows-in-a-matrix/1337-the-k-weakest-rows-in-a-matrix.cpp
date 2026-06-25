class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows;

        for (int i = 0; i < mat.size(); i++) {
            int soldiers = 0;
            for (int x : mat[i]) {
                soldiers += x;
            }
            rows.push_back({soldiers, i});
        }

        sort(rows.begin(), rows.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(rows[i].second);
        }

        return ans;
    }
};
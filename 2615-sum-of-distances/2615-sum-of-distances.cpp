class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto &p : mp) {
            vector<int> v = p.second;
            int m = v.size();

            vector<long long> pre(m, 0);
            pre[0] = v[0];

            for (int i = 1; i < m; i++) {
                pre[i] = pre[i - 1] + v[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = 1LL * v[i] * i - (i > 0 ? pre[i - 1] : 0);
                long long right = (pre[m - 1] - pre[i]) - 1LL * v[i] * (m - i - 1);
                res[v[i]] = left + right;
            }
        }

        return res;
    }
};
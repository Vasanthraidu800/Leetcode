class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int ans = 0;

        for (auto &r : a) {
            int s = 0;
            for (int x : r) {
                s += x;
            }
            ans = max(ans, s);
        }

        return ans;
    }
};
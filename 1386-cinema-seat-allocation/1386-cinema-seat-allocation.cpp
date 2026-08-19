class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &x : reservedSeats) {
            int r = x[0], s = x[1];

            if (s >= 2 && s <= 5)
                mp[r] |= 1;

            if (s >= 4 && s <= 7)
                mp[r] |= 2;

            if (s >= 6 && s <= 9)
                mp[r] |= 4;
        }

        long long ans = 2LL * n;

        for (auto &[r, mask] : mp) {
            if (mask == 7)
                ans -= 2;
            else if (mask != 0)
                ans -= 1;
        }

        return ans;
    }
};
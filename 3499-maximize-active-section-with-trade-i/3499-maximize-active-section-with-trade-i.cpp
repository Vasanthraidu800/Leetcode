class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int ones = 0;
        for (char c : s)
            ones += (c == '1');

        string t = "1" + s + "1";

        vector<pair<char,int>> v;

        for (char c : t) {
            if (v.empty() || v.back().first != c)
                v.push_back({c, 1});
            else
                v.back().second++;
        }

        int ans = ones;

        // only interior 1-blocks are removable
        for (int i = 2; i + 2 < (int)v.size(); i++) {

            if (v[i].first != '1') continue;
            if (v[i - 1].first != '0') continue;
            if (v[i + 1].first != '0') continue;

            ans = max(ans, ones + v[i - 1].second + v[i + 1].second);
        }

        return ans;
    }
};
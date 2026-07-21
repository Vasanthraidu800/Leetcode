class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";

        vector<pair<char,int>> v;

        for (char c : t) {
            if (v.empty() || v.back().first != c)
                v.push_back({c, 1});
            else
                v.back().second++;
        }

        int ans = ones;

        for (int i = 1; i + 1 < v.size(); i++) {
            if (v[i].first == '1' &&
                v[i - 1].first == '0' &&
                v[i + 1].first == '0') {

                ans = max(ans, ones + v[i - 1].second + v[i + 1].second);
            }
        }

        return ans;
    }
};
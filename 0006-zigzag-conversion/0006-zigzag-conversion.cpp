class Solution {
public:
    string convert(string s, int r) {
        if (r == 1) return s; // if only one row then no change in the string
        vector<vector<char>> v(r);
        int i = 0, n = s.size();
        while (i < n) {
            for (int j = 0; j < r && i < n; j++)
                v[j].push_back(s[i++]);  // top to bottom pushing
            for (int j = r - 2; j > 0 && i < n; j--)
                v[j].push_back(s[i++]); // bottom to top diagonal pushing
        }

        string ans = "";
        for (int i = 0; i < r; i++) {
            for (char c : v[i])
                ans += c;
        }

        return ans;
    }
};
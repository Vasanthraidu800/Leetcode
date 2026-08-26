class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), l = 0, cnt = 0, mn = n + 1;
        string ans = "";

        for (int r = 0; r < n; r++) {
            if (s[r] == '1') cnt++;

            while (cnt == k) {
                int len = r - l + 1;

                if (len < mn) {
                    mn = len;
                    ans = s.substr(l, len);
                } 
                else if (len == mn) {
                    string cur = s.substr(l, len);
                    if (ans.empty() || cur < ans)
                        ans = cur;
                }

                if (s[l] == '1') cnt--;
                l++;
            }
        }

        return ans;
    }
};
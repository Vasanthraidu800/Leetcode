class Solution {
public:
    int solve(string &s, int l, int r, int k) {
        if (r - l < k) return 0;

        vector<int> cnt(26, 0);
        for (int i = l; i < r; i++) {
            cnt[s[i] - 'a']++;
        }

        for (int i = l; i < r; i++) {
            if (cnt[s[i] - 'a'] < k) {
                int j = i + 1;
                while (j < r && cnt[s[j] - 'a'] < k) j++;
                return max(
                    solve(s, l, i, k),
                    solve(s, j, r, k)
                );
            }
        }

        return r - l;
    }

    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }
};
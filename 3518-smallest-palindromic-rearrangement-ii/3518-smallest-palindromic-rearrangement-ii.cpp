class Solution {
public:
    long long comb(int n, int r, int k) {
        r = min(r, n - r);

        long long ans = 1;

        for(int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;

            if(ans >= k)
                return k;
        }

        return ans;
    }

    long long count(vector<int>& f, int k) {
        int n = 0;

        for(int i = 0; i < 26; i++)
            n += f[i] / 2;

        long long ans = 1;

        for(int i = 0; i < 26; i++) {
            int x = f[i] / 2;

            if(x == 0)
                continue;

            ans = ans * comb(n, x, k);

            if(ans >= k)
                return k;

            n -= x;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> f(26, 0);

        for(char c : s)
            f[c - 'a']++;

        char mid = 0;

        for(int i = 0; i < 26; i++) {
            if(f[i] % 2)
                mid = 'a' + i;
        }

        // Check if kth palindrome exists
        if(count(f, k) < k)
            return "";

        int n = s.size() / 2;
        string half = "";

        for(int pos = 0; pos < n; pos++) {

            for(int c = 0; c < 26; c++) {

                if(f[c] < 2)
                    continue;

                f[c] -= 2;

                long long ways = count(f, k);

                if(ways >= k) {
                    half += char('a' + c);
                    break;
                }

                k -= ways;
                f[c] += 2;
            }
        }

        string ans = half;

        if(mid)
            ans += mid;

        reverse(half.begin(), half.end());

        ans += half;

        return ans;
    }
};
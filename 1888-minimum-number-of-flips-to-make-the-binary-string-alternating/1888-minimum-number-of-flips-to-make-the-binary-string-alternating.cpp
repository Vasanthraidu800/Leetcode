class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        int d1 = 0, d2 = 0, ans = n;

        for(int i = 0; i < 2*n; i++)
        {
            char c1 = (i % 2) ? '1' : '0';
            char c2 = (i % 2) ? '0' : '1';

            if(t[i] != c1) d1++;
            if(t[i] != c2) d2++;

            if(i >= n)
            {
                char p1 = ((i-n) % 2) ? '1' : '0';
                char p2 = ((i-n) % 2) ? '0' : '1';

                if(t[i-n] != p1) d1--;
                if(t[i-n] != p2) d2--;
            }

            if(i >= n-1)
                ans = min(ans, min(d1, d2));
        }

        return ans;
    }
};
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> p(n, true);
        p[0] = p[1] = false;

        int cnt = 1;

        for(int i = 3; i * i < n; i += 2) {
            if(p[i]) {
                for(int j = i * i; j < n; j += 2 * i)
                    p[j] = false;
            }
        }

        for(int i = 3; i < n; i += 2)
            if(p[i]) cnt++;

        return cnt;
    }
};
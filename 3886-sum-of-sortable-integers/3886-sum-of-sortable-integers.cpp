class Solution {
public:
    int sortableIntegers(vector<int>& a) {
        int n = a.size(), sum = 0;
        vector<int> s = a;
        sort(s.begin(), s.end());
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            bool ok = true;
            for (int i = 0; i < n; i += k) {
                vector<int> b(a.begin() + i, a.begin() + i + k);
                vector<int> t(s.begin() + i, s.begin() + i + k);
                int cnt = 0, p = -1;
                for (int j = 0; j < k; ++j) {
                    if (b[j] > b[(j + 1) % k]) { cnt++; p = j; }
                }
                if (cnt > 1) { ok = false; break; }
                int st = (cnt == 1) ? (p + 1) % k : 0;
                for (int l = 0; l < k; ++l) {
                    if (b[(st + l) % k] != t[l]) { ok = false; break; }
                }
                if (!ok) break;
            }
            if (ok) sum += k;
        }
        return sum;
    }
};
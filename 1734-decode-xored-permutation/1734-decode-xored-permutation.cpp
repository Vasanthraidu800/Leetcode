class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int x = 0;

        for (int i = 1; i <= n; i++)
            x ^= i;

        for (int i = 1; i < n; i += 2)
            x ^= encoded[i];

        vector<int> perm(n);
        perm[0] = x;

        for (int i = 0; i < n - 1; i++)
            perm[i + 1] = perm[i] ^ encoded[i];

        return perm;
    }
};
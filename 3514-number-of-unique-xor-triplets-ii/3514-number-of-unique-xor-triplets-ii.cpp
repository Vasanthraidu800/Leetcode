class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> present(MAXX, false);
        for (int x : nums)
            present[x] = true;

        vector<bool> one(MAXX, false), two(MAXX, false), three(MAXX, false);


        for (int v = 0; v < MAXX; v++)
            if (present[v])
                one[v] = true;

        for (int a = 0; a < MAXX; a++) {
            if (!one[a]) continue;
            for (int v = 0; v < MAXX; v++) {
                if (present[v])
                    two[a ^ v] = true;
            }
        }

        for (int a = 0; a < MAXX; a++) {
            if (!two[a]) continue;
            for (int v = 0; v < MAXX; v++) {
                if (present[v])
                    three[a ^ v] = true;
            }
        }

        int ans = 0;
        for (bool x : three)
            if (x) ans++;

        return ans;
    }
};
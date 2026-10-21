class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int b = 30; b >= 0; b--) {
            unordered_set<int> st;
            for (int x : nums)
                st.insert(x >> b);
            int cand = ans | (1 << b);
            bool ok = false;
            for (int x : nums) {
                int p = x >> b;
                if (st.count(cand >> b ^ p)) {
                    ok = true;
                    break;
                }
            }
            if (ok)
                ans = cand;
        }

        return ans;
    }
};
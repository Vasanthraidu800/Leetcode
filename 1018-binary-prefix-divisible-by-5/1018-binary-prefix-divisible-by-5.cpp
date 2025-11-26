class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int mod = 0;

        for (int bit : nums) {
            mod = (mod * 2 + bit) % 5;
            res.push_back(mod == 0);
        }

        return res;
    }
};

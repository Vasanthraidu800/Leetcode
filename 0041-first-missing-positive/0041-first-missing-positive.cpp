class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (int num : nums) {
            if (num > 0) { 
                mp[num] = true;
            }
        }

        int expected = 1;
        while (true) {
            if (mp.find(expected) == mp.end()) {
                return expected;
            }
            expected++;
        }
    }
};

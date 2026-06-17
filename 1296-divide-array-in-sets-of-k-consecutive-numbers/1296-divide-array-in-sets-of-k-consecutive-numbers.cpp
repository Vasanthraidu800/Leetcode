class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first;

            for (int i = 0; i < k; i++) {
                int num = start + i;

                auto it = freq.find(num);
                if (it == freq.end()) return false;

                if (--(it->second) == 0) {
                    freq.erase(it);
                }
            }
        }

        return true;
    }
};
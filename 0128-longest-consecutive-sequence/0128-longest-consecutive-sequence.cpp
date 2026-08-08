class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums)
            s.insert(x);
        int ans = 0;
        for(int x : s) {
            if(s.find(x - 1) == s.end()) {
                int len = 1;
                int y = x + 1;

                while(s.find(y) != s.end()) {
                    len++;
                    y++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};
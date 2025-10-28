class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int lsum = 0, rsum = 0;
                for (int j = 0; j < i; j++)
                    lsum += nums[j];
                for (int j = i + 1; j < n; j++)
                    rsum += nums[j];
                if (lsum == rsum) cnt += 2;
                else if (abs(lsum - rsum) == 1) cnt += 1;
            }
        }
        return cnt;
    }
};

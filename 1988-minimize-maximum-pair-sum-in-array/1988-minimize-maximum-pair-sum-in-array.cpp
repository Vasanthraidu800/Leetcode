class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] - 1;
        int size = n/2;
        for (int i = 0; i < size; i++) {
            res = max(res, nums[i] + nums[n-i-1]);
        }
        return res;
    }
};

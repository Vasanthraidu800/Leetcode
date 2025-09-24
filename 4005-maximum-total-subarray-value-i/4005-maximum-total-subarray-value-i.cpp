class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long n = nums.size();
        sort(nums.begin(),nums.end());
        long long  res = nums[n-1]-nums[0];
        return res * k;
    }
};
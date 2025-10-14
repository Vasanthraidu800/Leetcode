class Solution {
public:
    bool IsValid(int i, int k, vector<int>& nums)
    {
        for(int j = i; j < i + k - 1; j++)
        {
            if(nums[j] >= nums[j + 1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i + 2 * k <= n; i++)
        {
            if(IsValid(i, k, nums) && IsValid(i + k, k, nums))
                return true;
        }
        return false;
    }
};

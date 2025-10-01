class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n>1)
        {
            vector<int>newNums(n-1);
            int k = newNums.size();
            for(int i=0;i<k;i++)
            {
            newNums[i] = (nums[i]+nums[i+1])%10;
            }
            nums = newNums;
            n=nums.size();
        }
        return nums[0];
    }
};
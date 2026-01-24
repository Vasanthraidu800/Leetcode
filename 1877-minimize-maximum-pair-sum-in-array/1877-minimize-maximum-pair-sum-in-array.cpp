class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int>sum;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++)
        {
            sum.push_back(nums[i]+nums[n-1-i]);
        }
        sort(sum.begin(),sum.end());
        return sum[(n/2)-1];
    }
};
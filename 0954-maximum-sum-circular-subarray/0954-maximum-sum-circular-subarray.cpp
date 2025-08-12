class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
   int minSum = nums[0];
    int currSum = 0;
    for (int num : nums) 
    {
        currSum += num;
        minSum = min(minSum, currSum);
        if (currSum > 0) currSum = 0; 
    }

    int sum=0;
    for(int n:nums)
    {
        sum+=n;
    }
    
    int maxSum = nums[0];
    int curSum = 0;

    for (int num : nums) {
        curSum += num;
        maxSum = max(maxSum, curSum);
        if (curSum < 0) curSum = 0;
    }
    if(maxSum<0) return maxSum;// if all are negative elements case
    int res = max(maxSum,sum-minSum);
    return res;
    
    }
};
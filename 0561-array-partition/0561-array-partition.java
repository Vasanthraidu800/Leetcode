class Solution {
    public int arrayPairSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int max_sum=0;
        for(int i=0;i<n-1;i++)
        {
            if(i%2==0)
            max_sum+=nums[i];
        }
        return max_sum;
    }
}
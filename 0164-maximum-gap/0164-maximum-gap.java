class Solution {
    public int maximumGap(int[] nums) {
        Arrays.sort(nums);
        int max_diff=0;
        int n = nums.length;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]>max_diff)
            max_diff=nums[i+1]-nums[i];
        }
        return max_diff;
    }
}
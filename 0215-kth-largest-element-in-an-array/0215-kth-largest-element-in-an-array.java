class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        int n=nums.length;
        int j=0;
        int res=0;
        for(int i=n-1;i>=0;i--) 
        {
            j++;
            if(j==k)
            {
                res=nums[i];
                break;
            }
        }  
        return res; 
    }
}
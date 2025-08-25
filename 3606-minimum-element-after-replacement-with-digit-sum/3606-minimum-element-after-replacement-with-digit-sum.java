class Solution {
    public int minElement(int[] nums) {
        int m = nums.length;
        int[] res = new int[m];
        for(int i=0;i<m;i++)
        {
            int n = nums[i];
            int sum=0;
            while(n!=0)
            {
                int temp=n%10;
                sum+=temp;
                n/=10;
            }
            res[i]=sum;
        }
        int min=res[0];
        for(int i=0;i<m;i++)
        {
            if(res[i]<min)
            min = res[i];
        }
        return min;
    }
}
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n=nums.size();
        int ele_sum=0;
        int digit_sum=0;
        for(int i=0;i<n;i++)
        {
            ele_sum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=9)
            digit_sum+=nums[i];
            else
            {
                int temp=nums[i];
                while(temp>0)
                {
                    int r=temp%10;
                    digit_sum+=r;
                    temp/=10;
                }

            }
        }
        if(ele_sum>=digit_sum)
        return ele_sum-digit_sum;
        else
        return digit_sum-ele_sum;
    }
};
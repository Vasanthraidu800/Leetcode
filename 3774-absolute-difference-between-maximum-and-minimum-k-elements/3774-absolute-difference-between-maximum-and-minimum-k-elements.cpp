class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum1=0,sum2=0;
        for(int i=0;i<k;i++)
        {
            sum1+=nums[i];
        }
        int cnt=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum2+=nums[i];
            cnt++;
            if(cnt==k) break;
        }
        return abs(sum1-sum2);
    }
};
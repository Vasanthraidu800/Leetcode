class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n =  nums.size();
        sort(nums.begin(),nums.end());
        vector<int>res;
        int i=0;
        int j=n-1;
        while(i<j)
        {
            res.push_back(nums[i]+nums[j]);
            i++;
            j--;
        }
        int max=0;
        for(int i=0;i<res.size();i++)
        {
            if(res[i]>max) max=res[i];
        }
        return max;
    }
};
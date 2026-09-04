class Solution {
public:
int find_max(vector<int>&nums,int i,int n)
{
    int max=INT_MIN;
    for(int j=0;j<=i;j++)
    {
        if(nums[j]>max) max=nums[j];
    }
    return max;
}
int find_min(vector<int>&nums,int i,int n)
{
    int min=INT_MAX;
    for(int j=i;j<n;j++)
    {
        if(nums[j]<min) min=nums[j];
    }
    return min;
}

    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int st = find_max(nums,i,n) - find_min(nums,i,n);
            if(st<=k) return i;
        }
        return -1;
    }
};
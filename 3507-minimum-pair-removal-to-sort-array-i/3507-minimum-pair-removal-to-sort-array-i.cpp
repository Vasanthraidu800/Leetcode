class Solution {
public:
    bool is_sorted(vector<int>&nums)
    {
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    int min_sum(vector<int>&nums)
    {
        int n = nums.size();
        int min=INT_MAX;
        int min_index=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+nums[i+1]<min) 
            {min=nums[i]+nums[i+1];
            min_index=i;
            }
        }
        return min_index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int ops=0; // to cnt the no of operations

            while(!is_sorted(nums))// already sorted so no need any operations
            {
                int index = min_sum(nums);//finding minimum  dajacent sum everytime
                nums[index]=nums[index]+nums[index+1];
                nums.erase(nums.begin()+index+1);//removing second element from vector
                ops++;
            }
        return ops;
    }
};
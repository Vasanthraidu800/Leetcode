class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>res;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            res.push_back(nums[i]);
        }
        return res;
    }
};
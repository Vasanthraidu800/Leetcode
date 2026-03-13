class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto x : nums)mpp[x]++;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mpp.count(nums[i] + k))
            ans += mpp[nums[i]+k];
        }
        return ans;
    }
};
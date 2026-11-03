class Solution {
public:
    int minMoves(vector<int>& nums) {
       int mx = *max_element(nums.begin(),nums.end());
       long long ans = 0;
       int n = nums.size();
       for(int i=0;i<n;i++){
        ans += mx - nums[i];
       } 
       return ans;
    }
};
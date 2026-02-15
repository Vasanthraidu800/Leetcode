class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int s = -1, e = -1;
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                s = i;
                break;
            }
        }
        if(s == -1) return 0; 
        for(int i = n-1; i > 0; i--){
            if(nums[i] < nums[i-1]){
                e = i;
                break;
            }
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = s; i <= e; i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        while(s > 0 && nums[s-1] > mini) s--;
        while(e < n-1 && nums[e+1] < maxi) e++;

        return e - s + 1;
    }
};

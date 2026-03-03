class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
    
        for(int i = 0; i < n - 1; i++) {
            sum += abs(nums[i] - nums[i+1]);
        }
        
    
        int max_of_mins = INT_MIN;
        int min_of_maxs = INT_MAX;
        
        for(int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i+1];
            
            max_of_mins = max(max_of_mins, min(a, b));
            min_of_maxs = min(min_of_maxs, max(a, b));
        }
        
        int gain = max(0, 2 * (max_of_mins - min_of_maxs));

        //edge case
        for(int i = 1; i < n - 1; i++) {
            gain = max(gain,
                       abs(nums[0] - nums[i+1]) - abs(nums[i] - nums[i+1]));
            
           // gain = max(gain,
                       //abs(nums[n-1] - nums[i-1]) - abs(nums[i] - nums[i-1]));
        }

        
        return sum + gain;
    }
};
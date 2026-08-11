class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        while(1) {
            bool ok = true;
            for(int x : nums) {
                if(x == sum) {
                    ok = false;
                    break;
                }
            }

            if(ok) return sum;
            sum++;
        }
    }
};
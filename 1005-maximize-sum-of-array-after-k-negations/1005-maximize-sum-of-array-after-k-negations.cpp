class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int n = nums.size();
        // Flip negative numbers first
        while (i < n && nums[i] < 0 && k > 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }
        // If k is odd, flip the smallest element
        if (k % 2 == 1) {
            int mn = *min_element(nums.begin(), nums.end());
            for (int j = 0; j < n; j++) {
                if (nums[j] == mn) {
                    nums[j] = -nums[j];
                    break;
                }
            }
        }
        // Calculate sum
        int sum = 0;
        for (int x : nums) sum += x;

        return sum;
    }
};

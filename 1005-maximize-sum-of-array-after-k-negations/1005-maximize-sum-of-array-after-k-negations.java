class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {

        Arrays.sort(nums);

        int i = 0;
        int n = nums.length;

        // Flip negative numbers first
        while (i < n && nums[i] < 0 && k > 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }

        // If k is odd, flip the smallest element
        if (k % 2 == 1) {
            int minIndex = 0;
            for (int j = 1; j < n; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            nums[minIndex] = -nums[minIndex];
        }

        // Calculate sum
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        return sum;
    }
}

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long sum = 0;
        int minVal = nums[0];

        for (int num : nums) {
            sum += num;
            if (num < minVal) {
                minVal = num;
            }
        }

        return sum - (long)nums.size() * minVal;
    }
};
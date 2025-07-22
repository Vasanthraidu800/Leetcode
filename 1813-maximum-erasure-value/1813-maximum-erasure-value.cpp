class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> seen;
    int left = 0, right = 0, sum = 0, maxScore = 0;

    while (right < nums.size()) {
        while (seen.count(nums[right])) {
            sum -= nums[left];
            seen.erase(nums[left]);
            left++;
        }
        seen.insert(nums[right]);
        sum += nums[right];
        maxScore = max(maxScore, sum);
        right++;
    }

    return maxScore;
    }
};
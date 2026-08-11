class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int cnt = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                cnt++;
            }
            else {
                if(cnt != 3)
                    return nums[i - 1];

                cnt = 1;
            }
        }

        if(cnt != 3)
            return nums.back();

        return -1;
    }
};
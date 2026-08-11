class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int cnt = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                cnt++;
            }
            else {
                if(cnt == 1)
                    ans.push_back(nums[i - 1]);

                cnt = 1;
            }
        }

        // check last element
        if(cnt == 1)
            ans.push_back(nums.back());

        return ans;
    }
};
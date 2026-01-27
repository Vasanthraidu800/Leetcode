class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                res.push_back(nums[i]);
                pos.push_back(i);
            }
        }

        int m = res.size();
        if (m == 0) return nums;

        k %= m;
        rotate(res.begin(), res.begin() + k, res.end());

        for (int i = 0; i < m; i++) {
            nums[pos[i]] = res[i];
        }

        return nums;
    }
};

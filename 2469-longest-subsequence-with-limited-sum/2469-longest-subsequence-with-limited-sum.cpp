class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> res;

        sort(nums.begin(), nums.end());

        for (int j = 0; j < m; j++) {
            int req = queries[j];
            int sum = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (sum + nums[i] <= req) {
                    sum += nums[i];
                    cnt++;
                } else {
                    break;
                }
            }

            res.push_back(cnt);
        }

        return res;
    }
};

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i + k <= n; i++) 
        {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) freq[nums[j]]++;
            vector<pair<int, int>> vec(freq.begin(), freq.end());
            sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            int sum = 0;
            for (int m = 0; m < x && m < (int)vec.size(); m++)
                sum += vec[m].first * vec[m].second;
            res.push_back(sum);
        }
        return res;
    }
};

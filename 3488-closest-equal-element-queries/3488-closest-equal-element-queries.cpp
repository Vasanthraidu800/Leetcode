class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for (int q : queries) {
            int val = nums[q];
            vector<int>& pos = mp[val];
            
            if (pos.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            

            int idx = lower_bound(pos.begin(), pos.end(), q) - pos.begin();
            
            int minDist = INT_MAX;
            
            int left = (idx - 1 + pos.size()) % pos.size();
            int diff1 = abs(q - pos[left]);
            minDist = min(minDist, min(diff1, n - diff1));
            
            int right = (idx + 1) % pos.size();
            int diff2 = abs(q - pos[right]);
            minDist = min(minDist, min(diff2, n - diff2));
            
            ans.push_back(minDist);
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        unordered_map<int, vector<int>> mp; // key = group size
        vector<vector<int>> ans;            // final answer

        for (int i = 0; i < gs.size(); i++) {
            int size = gs[i];
            mp[size].push_back(i);          // add person i

            // if group is full
            if (mp[size].size() == size) {
                ans.push_back(mp[size]);    // add group
                mp[size].clear();           // start a new one
            }
        }
        return ans;
    }
};
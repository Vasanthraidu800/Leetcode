class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]]++;
        vector<pair<int, int>> v;
        for(auto x : mp)
            v.push_back(x);
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });

        int removed = 0;
        int cnt = 0;

        for(auto x : v) {
            removed += x.second;
            cnt++;

            if(removed >= n / 2)
                return cnt;
        }

        return cnt;
    }
};
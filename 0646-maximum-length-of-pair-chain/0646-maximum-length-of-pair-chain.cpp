class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int n = pairs.size();
        int cnt = 0;
        int last = -1000000;
        
        for(int i = 0; i < n; i++) {
            if(pairs[i][0] > last) {
                cnt++;
                last = pairs[i][1];
            }
        }
        
        return cnt;
    }
};
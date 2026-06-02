class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld,
                           vector<int>& ws, vector<int>& wd) {
        
        int ans = INT_MAX;
        int n = ls.size(), m = ws.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int lf = ls[i] + ld[i];
                int a = max(lf, ws[j]) + wd[j]; // land -> water

                int wf = ws[j] + wd[j];
                int b = max(wf, ls[i]) + ld[i]; // water -> land

                ans = min(ans, min(a, b));
            }
        }

        return ans;
    }
};
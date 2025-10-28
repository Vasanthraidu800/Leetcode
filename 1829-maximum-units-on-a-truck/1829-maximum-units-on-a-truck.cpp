bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] > b[1]; // sort by units per box descending
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(), b.end(), cmp); 

        int units = 0; // total units

        for (int i = 0; i < b.size(); i++) {
            int n = b[i][0]; 
            int x = b[i][1];
            int pick = min(n, t);
            units += pick * x;
            t-= pick;

            if (t == 0) break; // truck full
        }
        return units;
    }
};

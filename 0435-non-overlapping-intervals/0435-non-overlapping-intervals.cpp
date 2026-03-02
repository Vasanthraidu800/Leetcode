class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        
        if(a.size() == 0) return 0;

        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y){
            return x[1] < y[1];
        });

        int n = a.size();
        int c = 0;       
        int e = a[0][1];        

        for(int i = 1; i < n; i++) {
            if(a[i][0] < e) {
                c++;            
            }
            else {
                e = a[i][1]; 
            }
        }

        return c;
    }
};
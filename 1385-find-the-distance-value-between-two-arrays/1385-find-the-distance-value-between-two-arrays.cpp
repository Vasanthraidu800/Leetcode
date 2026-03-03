class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int n = a.size();
        int m = b.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            bool ok = true;
            
            for(int j = 0; j < m; j++) {
                if(abs(a[i] - b[j]) <= d) {
                    ok = false;
                    break;
                }
            }
            
            if(ok) count++;
        }
        
        return count;
    }
};
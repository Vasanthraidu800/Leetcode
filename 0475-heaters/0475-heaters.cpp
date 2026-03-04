class Solution {
public:
    int findRadius(vector<int>& a, vector<int>& b) {
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int i = 0, j = 0;
        int r = 0;
        
        while(i < a.size()) {
            
            while(j + 1 < b.size() && 
                  abs(b[j+1] - a[i]) <= abs(b[j] - a[i])) {
                j++;
            }
            
            int d = abs(b[j] - a[i]);
            r = max(r, d);
            
            i++;
        }
        
        return r;
    }
};
class Solution {
public:
    
    bool solve(vector<int>& arr, int i, vector<int>& vis) {
        
        if(i < 0 || i >= arr.size()) return false;
        
        if(vis[i] == 1) return false;
        
        if(arr[i] == 0) return true;
        
        vis[i] = 1;
        
        int jump = arr[i];
        
        return solve(arr, i + jump, vis) || 
               solve(arr, i - jump, vis);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        vector<int> vis(arr.size(), 0);
        
        return solve(arr, start, vis);
    }
};
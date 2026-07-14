class Solution {
    public:
    long  long dfs(vector<vector<int>>&grid, int i , int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i==m) return j; // if came to ending return column

        if(grid[i][j]==1 && (j+1<n) && grid[i][j+1]==1)
        return dfs(grid,i+1,j+1); // checking top down right case
        if(grid[i][j]==-1 && (j-1>=0) && grid[i][j-1]==-1)
        return dfs(grid,i+1,j-1); // checking  top down left case

        return -1; // if not possible
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int k = grid[0].size();
        vector<int>ans(k);
        for(int j=0 ; j<k;j++)
        {
            ans[j] = dfs(grid,0,j);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>ans;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                ans.push_back(grid[i][j]);
            }
        }
        int n = ans.size();
        k%=n;
        vector<int>mat;
        for(int m = n-k; m<n;m++)
        {
            mat.push_back(ans[m]); // pushing back last k elements from ans
        }
        for(int l = 0;l <n-k;l++)
        {
            mat.push_back(ans[l]); // pushing elements from starting to n-k in ans
        }
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size()));
        int idx=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                res[i][j]+=mat[idx++];
            }
        }
        return res;

    }
};
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int min_row=INT_MAX,max_row=INT_MIN,min_col=INT_MAX,max_col=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    min_row = min(min_row,i);
                    max_row = max(max_row,i);
                    min_col = min(min_col,j);
                    max_col = max(max_col,j);
                }
            }
        }
        int row_height=(max_row-min_row);
        int col_height=(max_col - min_col);
        return((row_height + 1)* (col_height + 1));
    }
};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) {
        int r = g.size();
        int c = g[0].size();
        int p = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(g[i][j] == 1) {
                    p += 4;
                    if(i > 0 && g[i-1][j] == 1) p--;
                    if(i < r-1 && g[i+1][j] == 1) p--;
                    if(j > 0 && g[i][j-1] == 1) p--;
                    if(j < c-1 && g[i][j+1] == 1) p--;
                }
            }
        }
        return p;
    }
};
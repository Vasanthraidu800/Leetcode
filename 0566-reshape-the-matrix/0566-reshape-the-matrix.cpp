class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& matrix, int r, int c) {
        int k  = matrix.size();
        int l = matrix[0].size();
        vector<int>mat;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<l;j++)
            {
                mat.push_back(matrix[i][j]);
            }
        } // pushed all matrix into 1-d array
         if(r*c !=mat.size()) return matrix;
        int m = mat.size(); 
        vector<vector<int>>res(r,vector<int>(c));
        m=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                res[i][j] = mat[m++];
            }
        }
        return res;
    }
};
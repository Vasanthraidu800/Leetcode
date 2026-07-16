class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        if(m*n !=org.size()) return {}; 
        int k = org.size(); 
        vector<vector<int>>res(m,vector<int>(n));
        k=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res[i][j] = org[k++];
            }
        }
        return res;
    }
};
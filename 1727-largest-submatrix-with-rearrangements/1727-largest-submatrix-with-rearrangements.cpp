class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        // build heights
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1)
                    matrix[i][j] += matrix[i-1][j];
            }
        }
        for(int i = 0; i < m; i++){
            vector<int> temp = matrix[i];
            sort(temp.begin(), temp.end(), greater<int>());

            for(int j = 0; j < n; j++){
                int area = temp[j] * (j + 1);
                ans = max(ans, area);
            }
        }

        return ans;
    }
};
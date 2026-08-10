class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int top = 0;
        int bottom = mat.size() - 1;
        int left = 0;
        int right = mat[0].size() - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {

            // Left -> Right case 
            for (int j = left; j <= right; j++)
                ans.push_back(mat[top][j]);
            top++;

            // Top -> Bottom case
            for (int i = top; i <= bottom; i++)
                ans.push_back(mat[i][right]);
            right--;

            // Right -> Left case
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans.push_back(mat[bottom][j]);
                bottom--;
            }

            // Bottom -> Top case
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(mat[i][left]);
                left++;
            }
        }

        return ans;
    }
};
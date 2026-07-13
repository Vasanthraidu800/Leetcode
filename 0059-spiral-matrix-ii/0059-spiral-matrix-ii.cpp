class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int x = 1;
        while (top <= bottom && left <= right) {

            // Left -> Right
            for (int j = left; j <= right; j++)
                mat[top][j] = x++;
            top++;

            // Top -> Bottom
            for (int i = top; i <= bottom; i++)
                mat[i][right] = x++;
            right--;

            // Right -> Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    mat[bottom][j] = x++;
                bottom--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    mat[i][left] = x++;
                left++;
            }
        }

        return mat;
    }
};
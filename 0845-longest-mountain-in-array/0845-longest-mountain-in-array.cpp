class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int up = 0, down = 0;
        int ans = 0;
        for (int i = 1; i < arr.size(); i++) {
            if ((down && arr[i] > arr[i-1]) || arr[i] == arr[i-1]) {
                up = down = 0;
            }
            if (arr[i] > arr[i-1])
                up++;
            else if (arr[i] < arr[i-1])
                down++;
            if (up && down)
                ans = max(ans, up + down + 1);
        }

        return ans;
    }
};
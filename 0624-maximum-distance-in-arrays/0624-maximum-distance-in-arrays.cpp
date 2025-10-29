class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int result = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();

        for (int i = 1; i < n; i++) {
            int currentMin = arrays[i][0];
            int currentMax = arrays[i].back();
            result = max(result, abs(currentMax - minVal));
            result = max(result, abs(maxVal - currentMin));
            minVal = min(minVal, currentMin);
            maxVal = max(maxVal, currentMax);
        }

        return result;
    }
};

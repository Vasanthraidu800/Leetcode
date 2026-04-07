class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;

    
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int lastEnd = points[0][1];

        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > lastEnd) {
                arrows++;                  // need new arrow
                lastEnd = points[i][1];    // update position
            }
        }

        return arrows;
    }
};
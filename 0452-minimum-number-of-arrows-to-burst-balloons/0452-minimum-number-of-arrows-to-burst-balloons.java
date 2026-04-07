import java.util.Arrays;

class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points.length == 0) return 0;

        // Sorting based on ending coordinate
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

        int arrows = 1;
        int lastEnd = points[0][1];

        for (int i = 1; i < points.length; i++) {
            if (points[i][0] > lastEnd) {
                arrows++;                 // need new arrow
                lastEnd = points[i][1];   // update end
            }
        }

        return arrows;
    }
}
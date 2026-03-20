import java.util.*;

class Solution {
    public int[][] minAbsDiff(int[][] g, int k) {
        
        int m = g.length;
        int n = g[0].length;
        
        int[][] ans = new int[m - k + 1][n - k + 1];
        
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                
                ArrayList<Integer> a = new ArrayList<>();
                
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        a.add(g[x][y]);
                    }
                }
                
                Collections.sort(a);
            
                ArrayList<Integer> b = new ArrayList<>();
                b.add(a.get(0));
                
                for (int t = 1; t < a.size(); t++) {
                    if (!a.get(t).equals(a.get(t - 1))) {
                        b.add(a.get(t));
                    }
                }
                
                int d = Integer.MAX_VALUE;
                
                for (int t = 1; t < b.size(); t++) {
                    d = Math.min(d, b.get(t) - b.get(t - 1));
                }
                
                if (d == Integer.MAX_VALUE) d = 0;
                
                ans[i][j] = d;
            }
        }
        
        return ans;
    }
}
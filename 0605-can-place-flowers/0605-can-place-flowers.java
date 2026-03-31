class Solution {
    public boolean canPlaceFlowers(int[] f, int n) {
        int s = f.length;
        int cnt = 0;

        for(int i = 0; i < s; i++) {
            if(f[i] == 0 &&
               (i == 0 || f[i-1] == 0) &&
               (i == s-1 || f[i+1] == 0)) {

                f[i] = 1;
                cnt++;
                i++; // skip next position
            }
        }
        return cnt >= n;
    }
}
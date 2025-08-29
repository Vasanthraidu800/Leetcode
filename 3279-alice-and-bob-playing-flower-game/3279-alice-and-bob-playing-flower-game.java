class Solution {
    public long flowerGame(int n, int m) {
        long even_x = n / 2;
        long odd_x  = (n + 1L) / 2;
        long even_y = m / 2;
        long odd_y  = (m + 1L) / 2;

        return odd_x * even_y + even_x * odd_y;
       
    }
}

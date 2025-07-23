class Solution {
    public boolean isFascinating(int n) {
        String s = "" + n + (2 * n) + (3 * n);  

        if (s.length() != 9) return false;  

        int[] freq = new int[10];

        for (int i = 0; i < 9; i++) {
            int digit = s.charAt(i) - '0';
            if (digit == 0) return false;  
            freq[digit]++;
        }
        for (int i = 1; i <= 9; i++) {
            if (freq[i] != 1) return false;
        }

        return true;
    }
}

class Solution {
    public boolean reorderedPowerOf2(int n) {
        String s = Integer.toString(n);
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        for (int i = 0; i < 31; i++) {
            int power = 1 << i;
            char[] pArr = Integer.toString(power).toCharArray();
            Arrays.sort(pArr);
            if (Arrays.equals(arr, pArr)) {
                return true;
            }
        }
        return false;
    }
}

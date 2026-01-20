class Solution {
    public long smallestNumber(long num) {

        if (num == 0) return 0;

        boolean neg = false;
        if (num < 0) {
            neg = true;
            num = -num;
        }

        char[] a = String.valueOf(num).toCharArray();
        java.util.Arrays.sort(a);

        if (neg) {
            for (int i = 0, j = a.length - 1; i < j; i++, j--) {
                char t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        } else {
            if (a[0] == '0') {
                for (int i = 1; i < a.length; i++) {
                    if (a[i] != '0') {
                        char t = a[0];
                        a[0] = a[i];
                        a[i] = t;
                        break;
                    }
                }
            }
        }

        long ans = Long.parseLong(new String(a));
        if (neg) ans = -ans;

        return ans;
    }
}

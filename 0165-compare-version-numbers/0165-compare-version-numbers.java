class Solution {
    public int compareVersion(String version1, String version2) {
        String[] parts1 = version1.split("\\.");
        String[] parts2 = version2.split("\\.");
        int l = parts1.length;
        int m = parts2.length;
        int k = Math.max(l,m);
        int ans = 0;
        for(int i=0;i<k;i++ )
        {
             int num1 = (i<l) ? Integer.parseInt(parts1[i]) : 0;
             int num2 = (i<m) ? Integer.parseInt(parts2[i]) : 0;

            if(num1<num2)
            {
                ans = -1;
                break;
            }
            if(num1>num2)
            {
                ans = 1;
                break;
            }
        }
        return ans;
    }
}
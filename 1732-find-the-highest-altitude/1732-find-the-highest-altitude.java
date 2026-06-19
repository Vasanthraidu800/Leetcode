class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;
        int k=n+1;
        int[] res= new int[k];
        res[0]=0;
        for(int i=1;i<n+1;i++)
        {
            res[i]=res[i-1]+gain[i-1];
        }
        int max=res[0];
        for(int i=1;i<k;i++)
        {
            if(res[i]>max)
            max=res[i];
        }
        return max;
    }
}
class Solution {
    public int divisorSubstrings(int num, int k) {
        String S=Integer.toString(num);
        int n=S.length();
        int cnt=0;
        for(int i=0;i<=n-k;i++)
        {
        String substring = S.substring(i,i+k);
        int res = Integer.parseInt(substring);
        if(res!=0 && num % res==0)
        {
        cnt++;
        }
        }
        return cnt;
    }
}
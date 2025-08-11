class Solution {
    public int numRescueBoats(int[] p, int l) {
        int n = p.length;
        Arrays.sort(p);
        int cnt=0;
        int left = 0;
        int right = n - 1;
        while(left<=right)
        {
            int sum = p[left] + p[right];
            if(sum<=l)
            {
                cnt++;
                left++;
                right--;
            }
            else{
                cnt++;
                right--;
            }
        }
        return cnt;
    }
}
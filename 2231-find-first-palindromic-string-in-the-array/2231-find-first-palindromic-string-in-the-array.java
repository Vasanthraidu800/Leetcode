class Solution {
    public String firstPalindrome(String[] words) {
        int n = words.length;
        String res="";
        for(int i=0;i<n;i++)
        {
            String org = words[i];
            String rev = new StringBuilder(org).reverse().toString();
            if(org.equals(rev))
            {
                res+=org;
                break;
            }
        }
        return res;
    }
}
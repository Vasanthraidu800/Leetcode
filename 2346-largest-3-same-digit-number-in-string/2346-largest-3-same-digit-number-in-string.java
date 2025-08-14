class Solution {
    public String largestGoodInteger(String s) {
        int n  = s.length();
        String sub = "";
        for(int i=0;i<=n-3;i++)
        {
            if(s.charAt(i)== s.charAt(i+1) && s.charAt(i)== s.charAt(i+2))
            {
             String temp = s.substring(i,i+3);
             if(temp.compareTo(sub)>0)
             sub=temp;
            }
        }
        return sub;
    }
}
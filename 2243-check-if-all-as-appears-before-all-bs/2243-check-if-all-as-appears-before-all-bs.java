class Solution {
    public boolean checkString(String s) {
        int n = s.length();
        boolean is_possible=true;
        for(int i=0;i<n-1;i++)
        {
            if(s.charAt(i)=='b' && s.charAt(i+1)=='a')
            {
                is_possible=false;
                break;
            }
        }
        return is_possible;
    }
}
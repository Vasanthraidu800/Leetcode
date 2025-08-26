class Solution {
    public int maximumValue(String[] strs) {
        int max=0;
        for(String s: strs)
        {
            max = Math.max(max,res(s));
        }
        return max;
}
private int res(String s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s.charAt(i) >= 'a' && s.charAt(i)<='z')
        {
            return s.length();
        }
    }
    return Integer.parseInt(s);
}
}
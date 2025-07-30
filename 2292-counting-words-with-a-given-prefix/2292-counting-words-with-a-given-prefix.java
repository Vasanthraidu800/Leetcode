class Solution {
    public int prefixCount(String[] words, String pref) {
        int cnt=0;
        for(String eachString :words)
        {
            if(eachString.startsWith(pref))
            cnt++;
        }
        return cnt;
    }
}
class Solution {
    public int reverseDegree(String s) {
         int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        char ch = s.charAt(i);
        if (ch >= 'a' && ch <= 'z') 
        {
            int reverseAlphabetPos = 26 - (ch - 'a'); 
            sum += reverseAlphabetPos * (i + 1);   
        }
    }
    return sum;
    }
}
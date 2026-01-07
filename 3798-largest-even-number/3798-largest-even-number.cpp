class Solution {
public:
    string largestEven(string s) {
        if((s[s.length() - 1] - '0') % 2 == 0) return s;
       int c = -1;
       string res;
       for(int i = s.length() - 1;i >= 0;i--) {
           if((s[i] - '0') % 2 == 0) {
               c = i;
               break;
           }
      }
     for(int i = 0;i <= c;i++) res += s[i];
        return res;
    }
};
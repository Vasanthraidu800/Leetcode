class Solution {
public:
    int balancedStringSplit(string s) {
        int rcnt=0;
        int lcnt=0;
        int result=0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
            rcnt++;
            else 
            lcnt++;
            if(rcnt==lcnt)
            result+=1;
        }
        return result;
    }
};
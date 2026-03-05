class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0  && s[i]!='0') c1++;
            if(i%2==1 && s[i]!='1') c1++;

            if(i%2==0  && s[i]!='1') c2++;
            if(i%2==1 && s[i]!='0') c2++;
        }
        return min(c1,c2);
    }
};
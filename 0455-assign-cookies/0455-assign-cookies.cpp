class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = s.size(), m =g.size();
        int cnt=0;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>=g[k]) 
            {
                cnt++;
                k++;
            }
            if(m <= k) return m;
        }
        return cnt;
    }
};
class Solution {
public:
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        int es=0,os=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) es+=p[i];
            else os+=p[i];
        }
        return (es!=os);
    }
};
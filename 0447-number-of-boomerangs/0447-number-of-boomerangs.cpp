class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n = p.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>m;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                int dx=p[i][0] - p[j][0];
                int dy=p[i][1] -p[j][1];
                int d = dx*dx+dy*dy;
                m[d]++;

            }
            for(auto x:m){
                int k=x.second;
                if(k>1)
                ans+=k*(k-1);
            }
        }
        return ans;
    }
};
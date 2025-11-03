class Solution {
public:
    int minCost(string c, vector<int>& n) {
        int m = c.size();
        int res = 0;
        int sum =n[0];
        int mx = n[0];
        for(int i=1;i<m;i++)
        {
            if(c[i]==c[i-1]) 
            {
                sum +=n[i];
                mx=max(mx,n[i]);
            }
            else
            {
                res += sum - mx;
                sum = n[i];
                mx= n[i];
            }
        }
        res+=sum-mx;
        return res;
    }
};
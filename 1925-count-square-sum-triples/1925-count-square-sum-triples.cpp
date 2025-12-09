class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int k=i*i+j*j;
                int ans=sqrt(k);
                if(ans*ans == k && ans<=n)
                cnt++;
            }
        }
        return cnt;
    }
};
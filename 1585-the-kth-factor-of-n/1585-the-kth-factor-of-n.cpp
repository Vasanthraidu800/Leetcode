class Solution {
public:
    int kthFactor(int n, int k) 
    {
        int fc=0;
        int res=-1;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            fc++;
            if(fc==k)
            {
                res=i;
                break;
            }
        }
        return res;
    }
};
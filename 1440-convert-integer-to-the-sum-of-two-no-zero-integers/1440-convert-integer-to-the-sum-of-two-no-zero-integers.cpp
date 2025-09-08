class Solution {
    bool contains_zero(int n)
    {
        while(n>0)
        {
            int r=n%10;
            if(r==0) return true;
            n=n/10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=0,b=0;
        vector<int>numbers;
        for(int i=1;i<n;i++)
        {
            a=i;
            b=n-i;
            if(contains_zero(a)==false && contains_zero(b)==false)
            {
                numbers.push_back(a);
                numbers.push_back(b);
                break;
            }
        }
        return numbers;
    }
};
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1=0,p2=0;
        if(z>=x)
        {
            p1=(z-x);
        }
        else p1 = x-z;
        if(z>=y)
        p2=z-y;
        else p2 =y-z;
        if(p1>p2)
        return 2;
        else if(p1==p2)
        return 0;
        else
        return 1;
    }
};
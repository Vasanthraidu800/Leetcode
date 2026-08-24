class Solution {
public:
    bool isPrime(int n) {
    if(n < 2) return false;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}
    vector<int> closestPrimes(int left, int right) {
        vector<int>p;
        for(int i=left;i<=right;i++)
        {
            if(isPrime(i)) p.push_back(i);

        }
        int diff = INT_MAX; int min1 =-1 , min2=-1;
        for(int i=1;i<p.size();i++)
        {
            if(p[i]-p[i-1]<diff){ diff=p[i]-p[i-1];
            min1 = p[i];
            min2 = p[i-1];
            }
        }
        vector<int>res;
        res.push_back(min2);
        res.push_back(min1);
        return res;
    }
};
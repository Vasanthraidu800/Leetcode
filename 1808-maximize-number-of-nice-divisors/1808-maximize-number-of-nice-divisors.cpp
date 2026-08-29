class Solution {
public:
    long long power(long long a, long long b) {
        long long res = 1;
        long long mod = 1e9 + 7;

        while(b) {
            if(b & 1)
                res = res * a % mod;

            a = a * a % mod;
            b >>= 1;
        }

        return res;
    }

    int maxNiceDivisors(int primeFactors) {
        long long k = primeFactors;

        if(k == 1)
            return 1;

        if(k % 3 == 0)
            return power(3, k / 3);

        if(k % 3 == 1)
            return power(3, k / 3 - 1) * 4 % (1000000007);

        return power(3, k / 3) * 2 % (1000000007);
    }
};
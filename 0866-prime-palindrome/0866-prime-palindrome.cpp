class Solution {
public:
    bool isPrime(int n) {
        if(n < 2) return false;
        if(n % 2 == 0) return n == 2;

        for(int i = 3; i * i <= n; i += 2)
            if(n % i == 0)
                return false;

        return true;
    }

    int makePal(int x) {
        int y = x;
        x /= 10;

        while(x) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return y;
    }

    int primePalindrome(int n) {
        if(n <= 11) {
            if(n <= 2) return 2;
            if(n <= 3) return 3;
            if(n <= 5) return 5;
            if(n <= 7) return 7;
            return 11;
        }

        for(int i = 1; ; i++) {
            int x = makePal(i);

            if(x >= n && isPrime(x))
                return x;
        }
    }
};
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int ans = 0;
        int p = 1;

        while(n > 0){
            int r = n % 2;

            if(r == 0) ans += p;

            p = p * 2;
            n = n / 2;
        }

        return ans;
    }
};
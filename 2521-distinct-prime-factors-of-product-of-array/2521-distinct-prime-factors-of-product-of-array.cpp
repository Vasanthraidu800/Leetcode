class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;

        for(int x : nums) {
            for(int p = 2; p * p <= x; p++) {
                if(x % p == 0) {
                    s.insert(p);
                    while(x % p == 0)
                        x /= p;
                }
            }

            if(x > 1)
                s.insert(x);
        }

        return s.size();
    }
};
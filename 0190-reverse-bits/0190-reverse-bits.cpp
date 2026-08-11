class Solution {
public:
    long long reverseBits(uint32_t n) {
        vector<int> v;

        for(int i = 0; i < 32; i++) {
            v.push_back(n % 2);
            n /= 2;
        }

        long long ans = 0;

        for(int i = 0; i < 32; i++) {
            ans = ans * 2 + v[i];
        }

        return ans;
    }
};
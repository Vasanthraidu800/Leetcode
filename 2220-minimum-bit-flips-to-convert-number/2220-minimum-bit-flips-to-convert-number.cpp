class Solution {
public:
    int minBitFlips(int start, int goal) {
        string a = bitset<32>(start).to_string();
        string b = bitset<32>(goal).to_string();

        int ans = 0;

        for(int i = 0; i < 32; i++) {
            if(a[i] != b[i])
                ans++;
        }

        return ans;
    }
};
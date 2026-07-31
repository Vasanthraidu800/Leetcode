class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), c = 0, j = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] - '0' == j)
                c++;

            j ^= 1;
        }

        return min(c, n - c);
    }
};
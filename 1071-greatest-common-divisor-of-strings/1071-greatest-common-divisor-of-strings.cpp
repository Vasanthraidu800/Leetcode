class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if (s1 + s2 != s2 + s1)
            return "";

        int n = s1.size();
        int m = s2.size();

        int g = gcd(n, m);

        return s1.substr(0, g);
    }
};
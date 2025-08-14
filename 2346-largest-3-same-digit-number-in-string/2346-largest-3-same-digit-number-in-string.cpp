class Solution {
public:
    string largestGoodInteger(string s) {
        string sub = "";
        int n = s.size();

        for (int i = 0; i <= n - 3; i++) {
            if (s[i] == s[i+1] && s[i] == s[i+2]) {
                string temp = s.substr(i, 3);
                if (sub.empty() || temp > sub) {
                    sub = temp;
                }
            }
        }
        return sub;
    }
};
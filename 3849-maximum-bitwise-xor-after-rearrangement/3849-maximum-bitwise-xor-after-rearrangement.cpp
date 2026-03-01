class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.length();
        int zero = 0, one = 0;
    
        for (int i = 0; i < n; i++) {
            if (t[i] == '0')
                zero++;
            else
                one++;
        }
        
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (one > 0) {
                    ans += '1';
                    one--;
                } else {
                    ans += '0';
                    zero--;
                }
            } else { 
                if (zero > 0) {
                    ans += '1';
                    zero--;
                } else {
                    ans += '0';
                    one--;
                }
            }
        }
        
        return ans;
    }
};
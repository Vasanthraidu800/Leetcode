class Solution {
public:
    long long smallestNumber(long long num) {
    
        if (num == 0) return 0;
        if (num < 0) {
            num = -num;  
            string s = to_string(num);
            sort(s.begin(), s.end(), greater<char>()); 
            return -stoll(s);
        }

        string s = to_string(num);
        sort(s.begin(), s.end()); 
        if (s[0] == '0') {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0') {
                    swap(s[0], s[i]);
                    break;
                }
            }
        }

        return stoll(s);
    }
};

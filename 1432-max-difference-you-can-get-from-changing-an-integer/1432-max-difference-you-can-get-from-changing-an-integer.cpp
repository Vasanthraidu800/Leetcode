class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s;
        char x;
        for (char c : a) {
            if (c != '9') {
                x = c;
                break;
            }
        }
        for (char &c : a) {
            if (c == x) c = '9';
        }
        string b = s;
        char y;
        
        if (b[0] != '1') {
            y = b[0];
            for (char &c : b) {
                if (c == y) c = '1';
            }
        } else {
            for (int i = 1; i < b.size(); i++) {
                if (b[i] != '0' && b[i] != '1') {
                    y = b[i];
                    for (char &c : b) {
                        if (c == y) c = '0';
                    }
                    break;
                }
            }
        }
        
        return stoi(a) - stoi(b);
    }
};
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<char> a;
        vector<char> b;

        for(int i = 0; i < n; i++) {
            if(s[i] == '#') {
                if(!a.empty()) a.pop_back();
            }
            else {
                a.push_back(s[i]);
            }
        }

        for(int i = 0; i < m; i++) {
            if(t[i] == '#') {
                if(!b.empty()) b.pop_back();
            }
            else {
                b.push_back(t[i]);
            }
        }

        return a == b;
    }
};
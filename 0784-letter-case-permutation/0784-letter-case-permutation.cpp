class Solution {
public:
    vector<string> res;
    void solve(string &s, int i) {
        if(i == s.size()) {
            res.push_back(s);
            return;
        }
        if(isalpha(s[i])) {
            s[i] = tolower(s[i]);
            solve(s, i + 1);

            s[i] = toupper(s[i]);
            solve(s, i + 1);
        }
        else {
            solve(s, i + 1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        solve(s, 0);
        return res;
    }
};
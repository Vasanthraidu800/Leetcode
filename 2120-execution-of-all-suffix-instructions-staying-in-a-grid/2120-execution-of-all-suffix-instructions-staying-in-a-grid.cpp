class Solution {
public:
    bool canMove(int r, int c, char ch, int n) {
        if(ch == 'L') c--;
        else if(ch == 'R') c++;
        else if(ch == 'U') r--;
        else r++;

        return r >= 0 && r < n && c >= 0 && c < n;
    }

    vector<int> executeInstructions(int n, vector<int>& sp, string s) {
        int m = s.size();
        vector<int> ans(m);

        for(int i = 0; i < m; i++) {
            int r = sp[0], c = sp[1];
            int cnt = 0;

            for(int j = i; j < m; j++) {
                if(!canMove(r, c, s[j], n))
                    break;

                if(s[j] == 'L') c--;
                else if(s[j] == 'R') c++;
                else if(s[j] == 'U') r--;
                else r++;

                cnt++;
            }

            ans[i] = cnt;
        }

        return ans;
    }
};
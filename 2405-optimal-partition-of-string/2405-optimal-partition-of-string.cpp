class Solution {
public:
    int partitionString(string s) {
        vector<char> v;
        int cnt = 1;

        for(char ch : s) {
            bool found = false;
            for(char x : v) {
                if(x == ch) {
                    found = true;
                    break;
                }
            }
            if(found) {
                cnt++;
                v.clear();
            }
            v.push_back(ch);
        }

        return cnt;
    }
};
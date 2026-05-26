class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> small(26, 0), cap(26, 0);
        
        for(char c : word) {
            if(c >= 'a' && c <= 'z')
                small[c - 'a'] = 1;
            else
                cap[c - 'A'] = 1;
        }
        
        int cnt = 0;
        
        for(int i = 0; i < 26; i++) {
            if(small[i] && cap[i])
                cnt++;
        }
        
        return cnt;
    }
};
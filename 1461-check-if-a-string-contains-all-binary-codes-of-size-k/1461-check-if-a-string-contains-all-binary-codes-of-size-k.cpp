class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        if (n - k + 1 < (1 << k))
            return false;
        
        unordered_set<string> st;
        
        for (int i = 0; i <= n - k; i++) {
            string temp = s.substr(i, k);
            st.insert(temp);
        }
        
        if (st.size() == (1 << k))
            return true;
        else
            return false;
    }
};
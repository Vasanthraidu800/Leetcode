class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        unordered_set<char> st;
        for(char ch : s) {
            if(st.count(ch)) {
                ans++;
                st.clear();
            }

            st.insert(ch);
        }
        return ans;
    }
};
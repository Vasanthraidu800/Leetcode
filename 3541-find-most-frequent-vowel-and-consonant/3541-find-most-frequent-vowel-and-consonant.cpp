class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vow , con;
        for(auto c : s)
        {
            if(c == 'a'|| c =='e' || c=='i' || c=='o' || c=='u') vow[c]++;
            else con[c]++;
        }
        int max_v = 0;
        int max_c = 0;
        for(auto x : vow)
        {
            if(x.second>max_v) max_v = x.second;
        }
        for(auto y : con)
        {
            if(y.second>max_c) max_c = y.second;
        }
        return max_v + max_c;
    }
};
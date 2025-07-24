class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
    string res = "";
    for (string word : words) {
        res += word[0];
    }
    return res == s;
    }
};
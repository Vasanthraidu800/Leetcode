class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        vector<pair<char, int>> vec;
        for (auto i = freq.begin(); i != freq.end(); i++) {
            vec.push_back({i->first, i->second});
        }
        int length = 0;
        bool oddFound = false;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].second % 2 == 0) 
            {
                length += vec[i].second;
            } else 
            {
                length += vec[i].second - 1;
                oddFound = true;
            }
        }

        if (oddFound) length++;
        return length; 
    }
};
class Solution {
public:
    int VowelCount(string s) {
        int cnt = 0;
        for (char c : s) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                cnt++;
        }
        return cnt;
    }

    string reverseWords(string s) {
        vector<string> words;
        string word = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }
        words.push_back(word);

        int first_cnt = VowelCount(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (VowelCount(words[i]) == first_cnt) {
                reverse(words[i].begin(), words[i].end());
            }
        }

        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};

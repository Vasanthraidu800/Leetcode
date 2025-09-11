class Solution {
public:
    bool isVowel(char ch) {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
               ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
    }

    string sortVowels(string s) {
        vector<char> vowels;

        // Collect vowels
        for (char c : s) {
            if (isVowel(c)) vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[k++];
            }
        }

        return s;
    }
};

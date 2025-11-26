class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int first[26], last[26];
        // setting initiall all occurrences to -1
        fill(first, first + 26, -1);
        fill(last, last + 26, -1);
        // storing first and last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }

        int result = 0;

        // for each character 'a' to 'z'
        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && last[c] > first[c]) {

                unordered_set<char> middle;

                // characters between first[c] and last[c]
                for (int i = first[c] + 1; i < last[c]; i++) {
                    middle.insert(s[i]);
                }

                result += middle.size();
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX);

        for (string &word : words) {
            vector<int> freq(26, 0);

            for (char c : word)
                freq[c - 'a']++;

            for (int i = 0; i < 26; i++)
                minFreq[i] = min(minFreq[i], freq[i]);
        }

        vector<string> ans;

        for (int i = 0; i < 26; i++) {
            while (minFreq[i]--) {
                ans.push_back(string(1, 'a' + i));
            }
        }

        return ans;
    }
};